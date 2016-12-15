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
 modified by eaman
 
 This example code is in the public domain.
 
 
 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

// constants won't change. Used here to 
// set pin numbers:
const int ledA = 13;      // Primo LED
const int ledB = 12;      // Secondo LED

// Variabbili di stato
int ledStateA = LOW;             // ledState used to set the LED
int ledStateB = LOW;             // ledState used to set the LED
              
long previousMillisA = 0;        // will store last time LED was updated
long previousMillisB = 0;        // will store last time LED was updated

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
  if (millis() > previousMillisA + intervalA) {
    // save the last time you blinked the LED 
    previousMillisA = millis();   

    // if the LED is off turn it on and vice-versa:
    if (ledStateA == LOW)
      ledStateA = HIGH;
    else
      ledStateA = LOW;
    // set the LED with the ledState of the variable:
    digitalWrite(ledA, ledStateA);
  }
  
// Secondo LED
    if (millis() > previousMillisB + intervalB) {
    // save the last time you blinked the LED 
    previousMillisB = millis();   

    // if the LED is off turn it on and vice-versa:
    if (ledStateB == LOW)
      ledStateB = HIGH;
    else
      ledStateB = LOW;
    // set the LED with the ledState of the variable:
    digitalWrite(ledB, ledStateB);
  }
}

/* Domande
 1. Provare a isolare il codice per accendere ogni singolo led in una funzione:
    - Quali variabili determinano il comportamento del LED?
    - Come cambiano durante il corso dello script?
    - Sono globali o locali? 
    - Quali parti vanno eseguite una sola volta e quali a ogni esecuzione?
 */



