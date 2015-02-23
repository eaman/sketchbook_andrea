/*
  Blink with Narcoleptic
  
  Normal Blink on a Uno uses 33.22 - 35.10ma
  Narcoleptic version on a Uno uses 24.38 - 26.08ma
  
  Normal Blink on a Nano uses 21.01 - 24.28ma
  Narcoleptic version on a Nano uses 6.73 - 9.75ma
  
  This should be way more efficient on a Arduino Mini 
  that has no USB chip - regulator. Arduino Mini should go from 17.2 to 3.2ma.
  
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
#include <Narcoleptic.h>
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
   Narcoleptic.delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
   Narcoleptic.delay(1000);               // wait for a second
}
