/*
  Blink due LED - Soluzione
 
 Aggiungere un secondo LED e farlo brillare ogni 500ms
 mentre il primo brilla ogni 1000ms
 
 a  |  b
 ========
 1  |  1
 1  |  0
 0  |  1 
 0  |  0
 
 Periodo = 500ms
 
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int ledA = 13; //Primo LED
int ledB = 12; //Secondo LED, con resistenza

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(ledA, OUTPUT);    
  pinMode(ledB, OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(ledA, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledB, HIGH);

  delay(500);               // Minimo comun denominatore del periodo
  //digitalWrite(ledA, HIGH); // ledA non cambia
  digitalWrite(ledB, LOW);


  delay(500);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, HIGH);

  delay(500);          
  //digitalWrite(ledA, LOW);  
  digitalWrite(ledB, LOW);


  delay(500);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  ;
}


















