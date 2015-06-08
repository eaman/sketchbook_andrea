/* Wire Slave Receiver

Ricezine di una stringa di testo via I2C

 This example code is in the public domain.
 
  Schema: http://lab.piffa.net/schemi/i2c_bb.jpg
*/

char input ;

#include <Wire.h>

void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  
  // Debug seriale
  Serial.begin(9600);           // start serial for output
  Serial.println("Slave / RX Debug:");
  Serial.flush();
}

void loop()
{

  delay(100);
// Nel Loop non succede niente, tutta l'azione e nella funzione receiveEvent()
// Innescata dall'evento Wire.onReceive
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  Serial.print("Lo slave ha ricevuto il seguente messaggio: ");
  while( Wire.available()) // loop through all but the last
  {
    input = Wire.read(); // receive byte as a character
    Serial.print(input);         // print the character
  }         // print the integer
  Serial.println("");
}

