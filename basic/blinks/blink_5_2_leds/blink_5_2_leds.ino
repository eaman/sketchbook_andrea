/*
  Blink v5
 
 Accensione e spegnimanto di 2 LED.
 Nel circuito oltre al LED montato direttamente sul pin 13
 viene aggiunto un altro LED pilotato dal PIN 12.
 
 Ricordarsi di usare una resistenza da ~320ohms per il secondo LED.
 Resistenza = (Voltaggio_Arduino - Forward_voltage_LED) / (ampere utilizzati)
 R = (5v-1.8v) / 0.010a 
 R =320ohms
 

 Schema: http://lab.piffa.net/schemi/led_single_bb.png
 - http://lab.piffa.net/schemi/led_single_schem.png

  This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int red = 12; // Definiamo un altro led
int breve = 200;  // Variabile richiambile nel corso dell'esecuzione
int lunga = 1000;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT); // Abilitaiamo entrambi i LED     
  pinMode(red, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(breve);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(breve);               // wait for a second

  digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(lunga);               // wait for a second
  digitalWrite(red, LOW);    // turn the LED off by making the voltage LOW
  delay(lunga); 
}


