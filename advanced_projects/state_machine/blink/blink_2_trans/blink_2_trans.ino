/*
  Blink FSM

  Accensione e spegnimanto di un LED utilizzando
  una FSM  con 4 stati, statici e di transizione.

Costrutto switch basato su uno struct.

 */

// Dichiarazione variabili
int led = 11; // PWM
int pausa = 1000;  // Variabile richiambile nel corso dell'esecuzione
byte lum = 0 ;

void setup() {
    // Inizializziamo il PIN 13 come OUTPUT
    pinMode(led, OUTPUT);
}

enum fsm_stati { // Stati della FMS
    on,     // Statico
    to_off, // Transizione
    off,
    to_on
};

fsm_stati stato ;

void loop() {
    switch (stato) {
    case on :
	// Operativa: Machine
        digitalWrite(led, HIGH);  // Mette il PIN del LED in stato acceso
        delay(pausa);              

	// Stati
        stato = to_off ; // Setta il prossimo state
        lum = 255;
        break;

    case to_off :
        while (lum > 0) {
            lum-- ;
            analogWrite(led, lum);  // Mette il PIN del LED in stato acceso
            delay(1);              
        }

        stato = off ; // Setta il prossimo state
        break;

    case off:
        digitalWrite(led, LOW);   // Mette il PIN del LED in stato spento
        delay(pausa);             

        stato = to_on ;
        lum = 0;
        break;

    case to_on :
        while (lum < 255) {
            lum++ ;
            analogWrite(led, lum);  // Mette il PIN del LED in stato acceso
            delay(1);              
        }

        stato = on ; // Setta il prossimo state
        break;
    }
}

/* Domande:

 1.Cosa comporta l'uso della funzione delay?
 2.Come si puo' modificare lo sketch per poter eseguire piu' conpiti contemporaneamente?

Esercizi successivi:
- Creare una FSM con un LED RGB avente due stati Red e Green, una transizione yellow tra i due
- Creare una FSM per la gestione di un semaforo 
	(esempio disponibile in sketchbook_andrea/advanced_projects/state_machine )

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
 .
 Soluzioni:

 1.Delay rende il codice blocking, null'altro puo' essere eseguito durante i delay
 2.Si potrebbe utilizzare millis(), vedi esercizi multitasking
*/
