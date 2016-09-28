/*
  Blink v4: while loop

 Accensione e spegnimanto di un LED utilizzando un ciclo
 iterativo while per comandare il lampeggio.

 Iterazione modificata da una variabile.
 
 */

const int led   = 13;   // Il valore non cambia
                        // durante l'esecuzione del programma
const int acceleratore = 30 ;                      
int tempo ; //

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
    
    tempo = acceleratore * iterator ; // Varia il tempo di blink
    brilla(tempo);              // accende e spegne rapidamente il LED 
                                // la pausa e' in funzione della variabile iteratore
  }
}

// Funzioni create dall'utente:
void brilla(int velocita) {
  // Accende e spegne il LED accetando un argomento 
  // per impostare la velocita'.

  // sequenze di istruzione: accendere e spegnere il LED
  digitalWrite(led, HIGH);       // Mette il PIN del LED in stato acceso)
  delay(velocita);               // Pausa
  digitalWrite(led, LOW);       // Mette il PIN del LED in stato spento
  delay(velocita);              // Pausa
}

