/*
   Semaforo RGB

   Un singolo semaforo costruito col paradigma delle macchine a stato.
   Viene utilizzato un oggetto della libreria common per gestire il LED.

   Uno stimolo esterno rappresentato dalla pressione di un bottone
   causa il passaggio di stato.

   Implementata con millis() invece che con delay(),
   sono stati aggiuntu due stati per meglio gestire lo stato yellow.

   */

#include <common.h>
const byte input = 2; // PIN del bottone
int pausa = 3000;
long timer ;
enum states_available { // Stati della FMS
    turn_green,    // Dinamico, transizione
    green,         // Statico
    wait_button,   // Evento - Stimolo
    turn_yellow,      // Dinamico, transizione
    yellow,            // Statico
    turn_red,      // Dinamico, transizione
    red            // Statico
};

states_available state  ;


void setup() {
  pinMode(input, INPUT_PULLUP);
  Serial.begin(9600);
  timer = millis();
}

RGBLed led(11, 10, 9); //Istanziamo un oggetto led facente parte
                       // della classe RGBLed

void loop() {
switch (state) {
    case turn_green :
    state = green ; // Setta il prossimo state
    break;

    case green:
    led.Green();
    if (millis() > timer + pausa * 2/3) {
    state = wait_button ;
    timer = millis(); 
    }
    break;

    case wait_button:
    if (digitalRead(input) == LOW) { 
    state = turn_yellow ; // Il passaggio di stato avviene alla pressione di un bottone
    timer = millis();
    delay(20); // Debouncing, si potrebbe fare con millis()
    };
    break;

    case turn_yellow :
    state = yellow ;
    break;

    case yellow :
    led.Yellow();
    if (millis() > timer + pausa * 2/3) {
    state = turn_red ;
    timer = millis(); 
    }
    break;

    case turn_red :
    state = red ;
    break;

    case red :
    led.Red();
    if (millis() > timer + pausa) {
    state = turn_green ;
    timer = millis(); 
    }
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
