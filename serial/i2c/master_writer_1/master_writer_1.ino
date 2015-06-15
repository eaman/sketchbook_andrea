/* Wire Master Writer

Invio dati via I2C

 Schema: http://lab.piffa.net/schemi/i2c_bb.jpg 
 This example code is in the public domain.
 
*/ 


#include <Wire.h>

void setup()
{
  Wire.begin(); // Entra sul canale I2C come master
}

byte x = 0;

void loop()
{
  Wire.beginTransmission(4); //Trasmette al device  #4
  Wire.write("Tora Tora!");        
  // sends one byte  
  Wire.endTransmission();    // stop transmitting


  delay(500);
}

