/*
  I2C comm: Slave LED
 
 Comunicazione I2C tra due schede Arduino.
 La  scheda master ha un bottone come input e 
 comunica con altre schede che monta un LED come output.
 Il led della seconda si accende quando rileva
 la pressione del bottone della prima.
 
 Schema: http://lab.piffa.net/schemi/i2c_bb.jpg
 */

#include <Wire.h>
//  slave
// PIN 0 = RX
int led = 13; // Questa scheda ha spolo l'output
int ledState = 0;         // stato attuale del LED
int incomingByte;   // Dato ricevuto via seriale


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);       // Il PIN e' attivato come output

  Serial.begin(9600); // Attiviamo la seriale per debug
  Serial.flush();
  Serial.println("Slave / RX Debug:");
  
  Wire.begin(2); // join i2c bus (address optional for master)
  Wire.onReceive(receiveEvent); // Evento in ricezione
}


void loop() {
  digitalWrite(led, ledState); // Aggiorna lo stato del LED
  delay(200);
}

/// Funzioni
void receiveEvent(int howMany)
{
  Serial.print("Lo slave ha ricevuto il seguente messaggio: ");
  while( Wire.available()) // loop through all but the last
  {
    incomingByte = Wire.read(); // receive byte as a character
    Serial.print(incomingByte, DEC);         // print the character

    if (incomingByte == 49) { // Verifica se viene ricevuto il dato 1
      ledState = !ledState ; // Cambia lo stato del LED 
    }        
    Serial.println("");
  }
}

/* Domande
 
 1. Implementare piu' bottoni per controllare piu' schede
 2. Implementare un messaggio di feedback dallo slave al master per uk cambio di stato del led  
 
 Links:

 */







