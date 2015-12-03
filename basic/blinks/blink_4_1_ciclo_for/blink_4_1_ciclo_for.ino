/*
  Blink v4: for loop

 Accensione e spegnimanto di un LED utilizzando un ciclo
 iterativo while per comandare il lampeggio.

 Reference: http://arduino.cc/en/Reference/for
 Altri esempi: sketchbook_andrea/programming/loops/

 */

const int led   = 13;   // Il valore non cambia
                        // durante l'esecuzione del programma


// /////////////////
// Setup: eseguita una volta sola all'accensione della scheda
void setup() {
    // initialize the digital pin as an output.
    pinMode(led, OUTPUT);
}

// ///////////////
// loop: Le istruzioni vengono eseguite all'infinito
void loop() {
for (int i = 0; i < 10; i++) { 
// (Definizione iteratore, condizione di verifica, gestione dell'iteratore)
// Operatore ternario (3 elementi)
// i++ incrementa di uno la variabile
    brilla(30 * i);      // accende e spegne rapidamente il LED
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


/* Domande

1.  Che differenza c'e' nella gestione dell'iteratore tra un ciclo
    while e for ?
2.  In quali casi si usa un ciclo for piuttosto che uno while?

.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
    Soluzioni
1.  Nel ciclo for l'iteratore e tutta la sua gestione avviene al di fuori
    del corpo della struttura del ciclo. Questa viene esplicitamente definita.
2.  Un ciclo for e' indicato per casi in cui si conosce e si vuole controllare
    il numero delle iterazioni. 
    Un ciclo while quando basta controllare
    il perdurare di una situazione di durata indefinita ad es. lo stato
    di un bottone. Es:

    while (stato_bottone = HIGH) {
    digitalWrite(LED, HI);
}
*/
