/*
  Blink v4: while loop

 Accensione e spegnimanto di un LED utilizzando un ciclo
 iterativo while per comandare il lampeggio.
 
 */

const int led   = 13;   // Il valore non cambia
                        // durante l'esecuzione del programm


// /////////////////
// Setup: eseguita una volta sola all'accensione della scheda
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// ///////////////
// loop: Le istruzioni vengono eseguite all'infinito
void loop() {
  int iterator = 0;    // Defniamo una variabile per controllare il ciclo iterativo
  while (iterator < 10) {       // Condizione del ciclo
    iterator = iterator + 1 ;   // incrementa l'iteratore
    brilla(30 * iterator);      // accende e spegne rapidamente il LED 
                                // la pausa e' in funzione della variabile iteratore
  }
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

