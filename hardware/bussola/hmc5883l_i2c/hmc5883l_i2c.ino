/*
An Arduino code example for interfacing with the HMC5883

by: Jordan McConnell
 SparkFun Electronics
 created on: 6/30/11
 license: OSHW 1.0, http://freedomdefined.org/OSHW

Analog input 4 I2C SDA
Analog input 5 I2C SCL

Link: https://www.sparkfun.com/tutorials/301
Datasheet e registri: http://dlnmh9ip6v2uc.cloudfront.net/datasheets/Sensors/Magneto/HMC5883L-FDS.pdf
*/

#include <Wire.h> //I2C Arduino Library

#define address 0x1E //0011110b, I2C 7bit address of HMC5883

void setup(){
  //Initialize Serial and I2C communications
  Serial.begin(9600);
  Wire.begin();
  
  //Put the HMC5883 IC into the correct operating mode
  Wire.beginTransmission(address); //open communication with HMC5883
  Wire.write(0x00); //select mode Measurement Configuration Bits
  Wire.write(0x70); // 8 -average, 15 Hz default, normal measuremen
  Wire.write(0x02); //select mode register
  Wire.write(0x00); //continuous measurement mode
  Wire.endTransmission();
}

void loop(){
  
  int x,y,z; //triple axis data

  //Tell the HMC5883 where to begin reading data
  Wire.beginTransmission(address);
  Wire.write(0x03); //select register 3, X MSB register
  Wire.endTransmission();
  
 
 //Read data from each axis, 2 registers per axis
  Wire.requestFrom(address, 6);
  if(6<=Wire.available()){
    x = Wire.read()<<8; //X msb
    x |= Wire.read(); //X lsb
    z = Wire.read()<<8; //Z msb
    z |= Wire.read(); //Z lsb
    y = Wire.read()<<8; //Y msb
    y |= Wire.read(); //Y lsb
  }
  
  //Print out values of each axis
  Serial.print("x: ");
  Serial.print(x);
  Serial.print("  y: ");
  Serial.print(y);
  Serial.print("  z: ");
  Serial.print(z);
  // Calcolo cotangente per gradi: https://it.wikipedia.org/wiki/Arcotangente2
  float radianti = atan2(x,y)  ;
  if (radianti < 0) {// Se y e'antiorario il segno e' inverso
    radianti += 2 * PI ; // inverte il segno
}
  
 float gradi = radianti * 180 / PI; // Conversione in gradi
 gradi += 2.56 ; // Correzione per la declinazione magnetica locale
 // Modena dovrebbe essere a +2° 34' positivi EST
  Serial.print("  gradi: ");
  Serial.println(gradi);
  
  delay(250);
}
