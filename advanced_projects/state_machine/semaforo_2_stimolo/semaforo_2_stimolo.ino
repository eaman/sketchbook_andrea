/*
   Semaforo RGB

   Un singolo semaforo costruito col paradigma delle macchine a stato.
   Viene utilizzato un oggetto della libreria common per gestire il LED.

   Uno stimolo esterno rappresentato dalla pressione di un bottone
   causa il passaggio di stato.

   */

#include <common.h>
const byte input = 2; // PIN del bottone
int pausa = 3000;
enum states_available { // Stati della FMS
    turn_green,    // Dinamico, transizione
    green,         // Statico
    wait_button,   // Evento - Stimolo
    turn_red,      // Dinamico, transizione
    red            // Statico
};

states_available state  ;


void setup() {
  pinMode(input, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.flush();
}

RGBLed led(11, 10, 9); //Istanziamo un oggetto led facente parte
                       // della classe RGBLed

void loop() {
switch (state) {
    case turn_green :
    led.Green();
    state = green ; // Setta il prossimo state
    break;

    case green:
    delay(pausa * 2/3);
    state = wait_button ;
    break;

    case wait_button:
    if (digitalRead(input) == LOW) { 
    state = turn_red ; // Il passaggio di stato avviene alla pressione di un bottone
    delay(20);
    };

    break;

    case turn_red :
    led.Yellow();
    delay(pausa/3);
    led.Red();
    delay(pausa);
    state = red ;
    break;

    case red :
    delay(pausa);
    state = turn_green ;
    break;

    default:    // In caso di default si fa giallo lampeggiante
    led.Yellow();
    delay(pausa/3);
    led.Off();
    delay(pausa/3);
    break;

}
Serial.print(millis()); 
Serial.print(" \t Stato attuale ");
Serial.println(state);

}

/* Domande:
 1. Introdurre un secondo semaforo che cambia stato quando viene attivato
    lo stimolo.
 2. L'uso di delay() puo' essere limitativo: come rimediare?
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
2. Si potrebbe utilizzare un interrupt per gli stimoli oppure millis()
   per gestire le pause.
 */
