/* Blink without Delay
 
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
 
 This example code is in the public domain.
 
 
 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

// constants won't change. Used here to 
// set pin numbers:
const int ledA =  13;      // the number of the LED pin
int ledB = 12; //Secondo LED

// Variables will change:
int ledStateA = LOW;             // ledState used to set the LED
int ledStateB = LOW;             // ledState used to set the LED

long previousMillisA = 0;        // will store last time LED was updated
long previousMillisB = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long intervalA = 1000;           // interval at which to blink (milliseconds)
long intervalB = 500;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledA, OUTPUT);      
  pinMode(ledB, OUTPUT);  
}

void loop()
{
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the 
  // difference between the current time and last time you blinked 
  // the LED is bigger than the interval at which you want to 
  // blink the LED.
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillisA > intervalA) {
    // save the last time you blinked the LED 
    previousMillisA = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledStateA == LOW)
      ledStateA = HIGH;
    else
      ledStateA = LOW;
    // set the LED with the ledState of the variable:
    digitalWrite(ledA, ledStateA);
  }
  
    if(currentMillis - previousMillisB > intervalB) {
    // save the last time you blinked the LED 
    previousMillisB = currentMillis;   

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
 2. Inserire un secondo LED con intervallo 500ms
 1. Trasformare il codice utilizzato in una State Machine
 
 */


