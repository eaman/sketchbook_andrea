/* Wire Slave Receiver

Ricezine di una stringa di testo via I2C

 This example code is in the public domain.
 
  Schema: http://lab.piffa.net/schemi/i2c_bb.jpg
*/

char input ;

#include <Wire.h>

void setup()
{
  Wire.begin(4);                // Entra sul canale I2C come slave  ID 4
  Wire.onReceive(receiveEvent); // Al verificarsi dell'evento Wire.onReceive
          // richiama la funzione receiveEvent()
          
  // Debug seriale
  Serial.begin(9600);           // start serial for output
  Serial.println("Slave / RX Debug:");
  Serial.flush();
}

void loop()
{
  delay(100);
// Nel Loop non succede niente, tutta l'azione e' nella funzione receiveEvent()
// Innescata dall'evento Wire.onReceive
}

// Funzioni
void receiveEvent(int howMany)
// Eseguita ogni volta che si riceve dati dal Master
{
  Serial.print("Lo slave ha ricevuto il seguente messaggio: \"");
  while ( Wire.available()) // Scansiona tutti i dati ricevuti
  {
    input = Wire.read(); // receive byte as a character
    Serial.print(input);         // print the character
  }         // print the integer
  Serial.println("\""); // \ e' l'escape character
}

