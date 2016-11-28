/*
  Blink v3
 Accensione e spegnimanto di un LED utilizzando un ciclo
 iterativo while per comandare il lampeggio.
 Questa volta il ciclo while() e' relegato in una funzione
 che accetta come argomento il numero di ripetizionei da effettuare.
 
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
  lampeggia(8);
  lento();  // accende e spegne lentamente il LED
  // Domanda: a quanto equivale iterator ora?
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

void lampeggia(int ripetizioni) {
  // Accende un LED per un numero stabilito di volte

  // Questa funziona accetta un parametro: ripetizioni
  int i = 0;
  while (i < ripetizioni) {
    rapido();   // accende e spegne rapidamente il LED
    i = i + 1 ; // incrementa l'iteratore
 // i++ ;       // equivalente
  }
}


/*  Esercizi:

 1. Preparare uno sketch contente le principali funzioni relative ai blinks
    preparate fino ad ora in modo da poterlo includere per poter riutilizzarle
    negli esercizi successivi.

*/


