/*
  I2C comm: Master
 
 Comunicazione I2C tra due schede Arduino.
 La  scheda master ha un bottone come input e 
 comunica con altre schede che monta un LED come output.
 Il led della seconda si accende quando rileva
 la pressione del bottone della prima.
 
 Questo script implementa il debounce con Millis()
 
 Schema: http://lab.piffa.net/schemi/i2c_bb.jpg
 */

#include <Wire.h>

int led = 13;
int input = 2;  // Questa e' la scheda con un input           
int statoAttuale;                        // variable for reading the pin status
int ultimoStato;                // variable to hold the last button state
long ultimoCambio = 0;  // Momento in cui e' stato attivato il PIN input
long debounceDelay = 100;    // Tempo di debounce

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);       // Il PIN e' attivato come output
  pinMode(input, INPUT_PULLUP);        // Il PIN e' attivato come output

  Serial.begin(9600); // Attiviamo la seriale per debug
  Serial.flush();
  Serial.println("Master Debug:");

  // Serial.begin(9600); // Attiviamo la seriale per debug
  Wire.begin(); // join i2c bus (address optional for master)
}


void loop() {
  statoAttuale = digitalRead(input);      // Legge lo stato del bottone

  if (statoAttuale == LOW && statoAttuale != ultimoStato && millis() - ultimoCambio > debounceDelay ) {
    // Trasmissione I2C
    Wire.beginTransmission(2); // Invia il messaggio al device slave con id 2
    Wire.write("1");
    Wire.endTransmission();    // stop transmitting

    // Gestone stato
    ultimoCambio = millis() ;    // Registra il tempo attuale


    // Request per lo stato del LED
    delay(100);
    Wire.requestFrom(2,1);
    while(Wire.available())    // slave may send less than requested
    {
      char statoRemoto = Wire.read(); // receive a byte as character
      Serial.print("Stato del LED sul device 2: ");
      Serial.println(statoRemoto,DEC);         // print the character
    }
  }
  ultimoStato = statoAttuale;                 // save the new state in our variable



}

/* Domande
 
 1. Implementare piu' bottoni per controllare piu' schede
 2. Isolare (per quanto possibile) la gestione di un BOTTONE-LED in una funzione 
    (es multitasking/BlinkWithoutDelay_3_funzione )
 3. Costruire una classi (programmazione ad oggetti) per l'oggetto BOTTONE-LED
    (es: multitasking/BlinkWithoutDelay_6_class/ )
 
 */





