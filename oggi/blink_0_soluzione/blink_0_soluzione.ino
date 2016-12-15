/*
  Blink due LED - Soluzione
 
 Aggiungere un secondo LED e farlo brillare ogni 500ms
 mentre il primo brilla ogni 1000ms
 
 Massimo comun denominatore 1000 MCD 500 = 500ms
 Durata Periodo = 500ms
 
 
 Stati: 
 
 a  |  b    Changes
 ========   =========
 1  |  1    x   |   x
 1  |  0        |   x
 0  |  1    x   |   x
 0  |  0        |   x
 
 
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
const int ledA = 13; //Primo LED
const int ledB = 12; //Secondo LED, con resistenza

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(ledA, OUTPUT);    
  pinMode(ledB, OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  // Primo periodo
  digitalWrite(ledA, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledB, HIGH);
  delay(500);               // Minimo comun denominatore del periodo

  // Secondo periodo
  //digitalWrite(ledA, HIGH); // ledA non cambia
  digitalWrite(ledB, LOW);
  delay(500);

  // Terzo periodo
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, HIGH);
  delay(500);

  // Quarto periodo
  //digitalWrite(ledA, LOW);  
  digitalWrite(ledB, LOW);
  delay(500);
}

/* Domande
 1. Altro scenartio: fare brillare un LED ogni 300ms mentre il secondo brilla ogni 400m
 2. ...valutare come aggiungere un terzo LED, gestire altri intevalli.
 */




















