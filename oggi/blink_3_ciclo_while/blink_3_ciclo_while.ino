/*
  Blink v4: while loop

 Accensione e spegnimanto di un LED utilizzando un ciclo
 iterativo while per comandare il lampeggio.

 */

int led   = 13;   // LED OnBoard


// /////////////////
// Setup: eseguita una volta sola all'accensione della scheda
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}

// ///////////////
// loop: Le istruzioni vengono eseguite all'infinito
void loop() {
  int iterator = 0;           // Defniamo una variabile per controllare il ciclo iterativo
  while (iterator < 10) {     // Condizione del ciclo

   rapido();
    iterator = iterator + 1 ;   // incrementa l'iteratore
  }

lento();
}

// Funzioni create dall'utente:
void rapido() {
  // Accende e spegne rapidamente il LED
  int breve = 200;
  // sequenze di istruzione: accendere e spegnere il LED
  digitalWrite(led, HIGH);    // Mette il PIN del LED in stato acceso
  delay(breve);               // Pausa
  digitalWrite(led, LOW);     // Mette il PIN del LED in stato spento
  delay(breve);               // Pausa
}


void lento() {
  // Accende e spegne lentamente il LED
  int lunga = 1000;
  // sequenze di istruzione: accendere e spegnere il LED
  digitalWrite(led, HIGH);    // Mette il PIN del LED in stato spento)
  delay(lunga);               // Pausa
  digitalWrite(led, LOW);     // Mette il PIN del LED in stato spento
  delay(lunga);               // Pausa
}
