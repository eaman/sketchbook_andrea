/*
  Blink con funzioni.
  
  Le funzioni sono una sequenza di istruzione raggruppate appunto in un a funzione.
  Le funzioni possono accettare argomenti e avere questi pre-impostati a valori di default se omessi.
  Le funzioni possono limitarsi a svolgere istruzionioppure elaborare valori restituendo un risultato.
  
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  lunga() ;
  lunga() ;
  breve();
  breve();
  varia(3000);
}

// Funzioni personalizzate: nella scheda funzioni.
