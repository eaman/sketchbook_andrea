/* Blink without Delay - due led
 
 Turns on and off a light emitting diode(LED) connected to a digital  
 pin, without using the delay() function.  This means that other code
 can run at the same time without being interrupted by the LED code.
 
 The circuit:
 * LED attached from pin 13 to ground.
 * Note: on most Arduinos, there is already an LED on the board
 that's attached to pin 13, so no hardware is needed for this example.
 
 
 created 2005
 by David A. Mellis
 modified 8 Feb 2010
 by Paul Stoffregen
 modified by Andrea Manni
 
 This example code is in the public domain.
 
 
 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

// constants won't change. Used here to 
// set pin numbers:
const int ledA = 13;      // Primo LED
const int ledB = 12;      // Secondo LED

// Variabbili di stato
int ledStateA = LOW;             // ledState used to set the LED
//int ledStateB = LOW;           // Not used
              
long previousMillisA = 0;        // will store last time LED was updated
unsigned long previousMillisB = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long intervalA = 1000;           // interval at which to blink (milliseconds)
long intervalB = 500;            // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledA, OUTPUT);      
  pinMode(ledB, OUTPUT);  
}

void loop()
{
// Primo LED
  if (millis() - previousMillisA >= intervalA) {
    // Timestamp + timestamp = delta temporale
    previousMillisA += intervalA ;

    // if the LED is off turn it on and vice-versa:
     ledStateA = !ledStateA;
    // set the LED with the ledState of the variable:
    digitalWrite(ledA, ledStateA);
  }
  
// Secondo LED: contratta
    if (millis() - previousMillisB >= intervalB) {
    digitalWrite(ledB, !digitalRead(ledB));
    previousMillisB += intervalB ;
  }
}

/* Domande
 1. Provare a isolare il codice per accendere ogni singolo led in una funzione:
    - Quali variabili determinano il comportamento del LED?
    - Come cambiano durante il corso dello script?
    - Sono globali o locali? 
    - Quali parti vanno eseguite una sola volta e quali a ogni esecuzione?
 */



