
// ////////////
// Commento iniziale
/*
  Blink v2

 Accensione e spegnimanto di un LED utilizzando funzioni
 per comandare il lampeggio.

 This example code is in the public domain.
 */
// //////////////
// Dichiarazione variabili

int led = 13; // LED onboard sulla scheda


// /////////////////
// Setup: eseguita una volta sola all'accensione della scheda
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}

// ///////////////
// loop: Le istruzioni vengono eseguite all'infinito
void loop() {
  // S
  rapido(); // accende e spegne rapidamente il LED
  rapido();
  rapido();

  // O
  lento();  // accende e spegne lentamente il LED
  lento();
  lento();

  // S
  rapido(); // accende e spegne rapidamente il LED
  rapido();
  rapido();


  //Funzione apposita:
  esse();
  ooo();
  esse();
}


  // ///////////////
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

void esse() {
  // Emette una lettera S in Morse

  int breve = 200;
  
  // sequenze di istruzione: accendere e spegnere il LED
  digitalWrite(led, HIGH);    // Mette il PIN del LED in stato acceso
  delay(breve);               // Pausa
  digitalWrite(led, LOW);     // Mette il PIN del LED in stato spento
  delay(breve);               // Pausa

  digitalWrite(led, HIGH);    // Mette il PIN del LED in stato acceso
  delay(breve);               // Pausa
  digitalWrite(led, LOW);     // Mette il PIN del LED in stato spento
  delay(breve);               // Pausa

  digitalWrite(led, HIGH);    // Mette il PIN del LED in stato acceso
  delay(breve);               // Pausa
  digitalWrite(led, LOW);     // Mette il PIN del LED in stato spento
  delay(breve);               // Pausa
}

void ooo() {
  // Emette una lettera o in Morse

  int lunga = 1000;
  // sequenze di istruzione: accendere e spegnere il LED
  digitalWrite(led, HIGH);    // Mette il PIN del LED in stato spento)
  delay(lunga);               // Pausa
  digitalWrite(led, LOW);     // Mette il PIN del LED in stato spento
  delay(lunga);               // Pausa

  digitalWrite(led, HIGH);    // Mette il PIN del LED in stato spento)
  delay(lunga);               // Pausa
  digitalWrite(led, LOW);     // Mette il PIN del LED in stato spento
  delay(lunga);               // Pausa

  digitalWrite(led, HIGH);    // Mette il PIN del LED in stato spento)
  delay(lunga);               // Pausa
  digitalWrite(led, LOW);     // Mette il PIN del LED in stato spento
  delay(lunga);               // Pausa

}

void sos() {
  // Emette un segnale di S.O.S

}

//////////////////
/* Domande:
    1. Che differenza c'e' tra le funzioni esse() e sos()?
 
 Soluzioni a fondo pagina.
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


 
 
 
 Risposta:

 1. esse() e' una funzione autonoma, puo' essere copiata/incollata in qualunque
 sketch e funzionera' autonomamente.
 sos() invece e' composta da altre funzioni: anche queste dovranno essere disponibili.

 */
