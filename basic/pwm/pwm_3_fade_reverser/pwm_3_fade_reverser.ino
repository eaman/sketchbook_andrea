/*
Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 This example code is in the public domain.
 From Arduino for dummies.
 */

int led = 9;
int brightness = 0; // this two could be bytes as well
int fadeAmount = 5;
// the pin that the LED is attached to
// how bright the LED is
// how many points to fade the LED by
// the setup routine runs once when you press reset:

void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}
// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  // wait for 30  milliseconds to see the dimming effect
  delay(30); // Question: should this value be here?
             // Would it be better to have a variable for it? Why?
}






