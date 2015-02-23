/*
  Blink v2
 
 Accensione e spegnimanto di un LED utilizzando funzioni
 per comandare il lampeggio.
 
 This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int breve = 200;  // Variabile richiambile nel corso dell'esecuzione
int lunga = 1000;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  rapido(); // accende e spegne rapidamente il LED
  rapido(); // accende e spegne rapidamente il LED
  lento();  // accende e spegne lentamente il LED
}

// Funzioni create dall'utente:

void rapido() {
  // Accende e spegne rapidamente il LED

  // sequenze di istruzione: accendere e spegnere il LED
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(breve);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(breve);               // wait for a second
}

void lento() {  
  // Accende e spegne lentamente il LED

  // sequenze di istruzione: accendere e spegnere il LED
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(lunga);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(lunga); 
}



