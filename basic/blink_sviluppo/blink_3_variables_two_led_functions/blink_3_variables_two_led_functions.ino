/*
  Blink v3
 Now with 2 variables and an extra LED (remember a ~320 ohms resistor).
 Turns on an LED on for one second, then off for one second, repeatedly.
 
 This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int red = 12;
int breve = 200;
int lunga = 1000;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  pinMode(red, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
lightRed();
lightGreen();
}

void lightRed() {
  digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(lunga);               // wait for a second
  digitalWrite(red, LOW);    // turn the LED off by making the voltage LOW
  delay(lunga); 
}

void lightGreen() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(breve);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(breve);               // wait for a second
}

