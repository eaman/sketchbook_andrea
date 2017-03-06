/*
  Blink FSM

  Accensione e spegnimanto di un LED utilizzando
  una FSM 2 stati statici.

Costrutto switch basato su uno struct.

 */

// Dichiarazione variabili
int led = 13;
int pausa = 500;  // Variabile richiambile nel corso dell'esecuzione

void setup() {
    // Inizializziamo il PIN 13 come OUTPUT
    pinMode(led, OUTPUT);
}

enum fsm_stati { // Stati della FMS
    on,
    off
};

fsm_stati stato;

void loop() {
    switch (stato){
    case on :
        digitalWrite(led, HIGH);  // Mette il PIN del LED in stato acceso
        delay(pausa);              // Aspetta un secondo (mille millisecondi)

        stato = off ; // Setta il prossimo state
        break;

    case off:
        digitalWrite(led, LOW);   // Mette il PIN del LED in stato spento
        delay(pausa);               // Aspetta mezzo secondo

        stato = on ;
        break;
    }
}
