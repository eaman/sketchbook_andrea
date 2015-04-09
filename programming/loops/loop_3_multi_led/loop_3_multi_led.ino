/*
  For Loop Iteration
 
 Demonstrates the use of a for() loop.
 Lights multiple LEDs in sequence, then in reverse.
 
 The circuit:
 * LEDs from pins 2 through 9 to ground
 
 Schemi:
 - http://lab.piffa.net/schemi/8_led_single_res_bb.png
 - http://lab.piffa.net/schemi/8_led_single_res_schem.png
 
 
 http://www.arduino.cc/en/Tutorial/ForLoop
 */

int timer = 100;           // The higher the number, the slower the timing.

void setup() {
  // use a for loop to initialize each pin as an output:
  for (int thisPin = 2; thisPin <= 9; thisPin++)  {
    pinMode(thisPin, OUTPUT);      
  }
}

void loop() {
  // loop from the lowest pin to the highest:
  for (int thisPin = 2; thisPin < 9; thisPin++) {
    // turn the pin on:
    digitalWrite(thisPin, HIGH);  
    delay(timer);                  
    // turn the pin off:
    digitalWrite(thisPin, LOW);    
  }

  // loop from the highest pin to the lowest:
  for (int thisPin = 9; thisPin > 2; thisPin--) {
    // turn the pin on:
    digitalWrite(thisPin, HIGH);
    delay(timer);
    // turn the pin off:
    digitalWrite(thisPin, LOW);
  }
}
