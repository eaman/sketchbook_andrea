/* Wire Master Writer

Invio dati via I2C

 Schema: http://lab.piffa.net/schemi/i2c_bb.jpg 
 This example code is in the public domain.
 
*/ 


#include <Wire.h>

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
}

byte x = 0;

void loop()
{
  //  Wire.beginTransmission(4); // transmit to device #4
  //  Wire.write("DAto inviato dal master");        // sends five bytes
  //
  //  Wire.endTransmission();    // stop transmitting
  //
  //
  //  delay(500);
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("Tora Tora!");        // sends five bytes
  // sends one byte  
  Wire.endTransmission();    // stop transmitting


  delay(500);
}

