/*
Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 This example code is in the public domain.
 From Arduino for dummies.
 */

const int led = 9;          // LED con PWM
byte brightness = 0;        // Luminosita'
const int fadeAmount = 5;   // Step di modifica luminosita'
const int pause = 30;       // Pausa tra incrementi


void setup() {
  pinMode(led, OUTPUT); // declare pin 9 to be an output:
}

void loop() {

  analogWrite(led, brightness);
  brightness = brightness + fadeAmount;

  if (brightness == 0 || brightness == 255) {
  // Invertire incremento ai valori limiti
    fadeAmount = -fadeAmount ;
  }
  // wait for 30  milliseconds to see the dimming effect
  delay(pause); 
}


/* Domande:
   1. Che rapporto c'e' tra un OR e due cicli IF ?
   2. E tra un AND e due cicli IF ?
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
Soluzioni:
   1. Due cicli IF sequenziali con:
    - Condizioni diverse
    - stessa conseguenza

   2. Due cicli IF annidiati che verificano due condizioni in sucessione
   
*/
