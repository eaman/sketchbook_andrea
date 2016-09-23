// ////////////
// Commento iniziale
/*
  Blink v1

  Accensione e spegnimanto di un LED utilizzando variabili
  per impostare la velocita' del lampeggio.
  
 */
 
// //////////////
// Dichiarazione variabili

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int breve = 200;  // Variabile richiambile nel corso dell'esecuzione
int lunga = 1000;

// /////////////////
// Setup: eseguita una volta sola all'accensione della scheda
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// ///////////////
// loop: Le istruzioni vengono eseguite all'infinito
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(breve);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(breve);               // wait for a second

  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(lunga);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(lunga); 
}
