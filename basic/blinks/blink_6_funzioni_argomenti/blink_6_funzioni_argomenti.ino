/*
  Blink v6
  
 Due LEDs con funzioni che accettano argomenti:
 gli argomenti permettono di modificar il comportamento
 delle funzioni.
 
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
lightRed(lunga);
lightRed(breve);

lightGreen(breve);
lightGreen(lunga);
}

void lightRed(int length) { // Argomento
  digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(length);               // wait for a second
  digitalWrite(red, LOW);    // turn the LED off by making the voltage LOW
  delay(length); 
}

void lightGreen(int  length) {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(length);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(length);               // wait for a second
}
  
  // Test: creare una funzione generica che permetta di accendere
  // qualunque LED per un periodo di tempo impostabile
  
  // Suggerimento: quanti parametri deve accettare?
