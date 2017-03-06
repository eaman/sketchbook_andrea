void brilla(int velocita = 1000); // Function prototype con valore di default
// _Deve_ essere dichiarato in alto, arduino sbaglia a creare i prototipi.
// Altro modo: metterle in un "tab" functions.h e includere questo
/*
  Blink v2
 
 Accensione e spegnimanto di un LED utilizzando funzioni
 per comandare il lampeggio.
 
 This example code is in the public domain.
 */

// Dichiarazione variabili

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
// Le variabili lunga e breve non sono piu' necessarie

// /////////////////
// Setup
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// loop
void loop() {
  brilla(300);
  brilla(300);
  brilla(); // default
}

// Funzioni create dall'utente:

void brilla(int velocita) {
  // Accende e spegne il LED accetando un argomento 
  // per impostare la velocita'.

  // sequenze di istruzione: accendere e spegnere il LED
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(velocita);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(velocita);               // wait for a second
}



/* Domande:
 *  1. Come si potrebbe fare per poter utilizzare la funzione brilla
 *     con PIN diversi rispetto a LED?
 * 
 *   2. Esercizio: creare uno sketch per far brillare un led 10 volte lentamente
 *      e dieci volte rapidamente.
 *  
 *  Esercizi sucessivi sulle funzioni: blink_5 e 6
 */
