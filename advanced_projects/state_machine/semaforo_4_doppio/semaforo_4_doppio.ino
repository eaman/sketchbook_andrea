/*
   Semaforo RGB


   Doppio semaforo, una via prinicipale (led) e una secondaria (secondary):
   la via secondaria ottiene la precedenza alla pressione di un bottone.

   Implementata con millis() invece che con delay(),
   sono stati aggiuntu due stati per gestire lo stato yellow 
   del semafor secondario.

   Lo sketch e' stato implementato con una sola FSM in cui si incrociano
   gli stati dei due semafori.

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
    turn_sec_yellow,  // Yellow per semaforo secondario
    sec_yellow,
    red            // Statico
};

states_available state  ;


void setup() {
  pinMode(input, INPUT_PULLUP);
  Serial.begin(9600);
  timer = millis();
}

RGBLed led(11, 10, 9);      // Semaforo principale
RGBLed secondary(8,7,6);    // Semaforo secondario
                       

void loop() {
switch (state) {
    case turn_green :
    led.Green();
    secondary.Red() ;
    state = green ; // Setta il prossimo state
    break;

    case green:
    if (millis() - timer => pausa * 2/3) {
    state = wait_button ;
    timer += pausa * 2/3 ;
    }
    break;

    case wait_button:
    if (digitalRead(input) == LOW) { 
    delay(20); // Debouncing, si potrebbe fare con millis()
    state = turn_yellow ; // Il passaggio di stato avviene alla pressione di un bottone
    timer = millis();
    };

    break;

    case turn_yellow :
    led.Yellow();
    state = yellow ;
    break;

    case yellow :
    if (millis() - timer >= pausa / 3) {
    state = turn_red ;
    timer += pausa / 3;
    }
    break;

    case turn_red :
    led.Red();
    secondary.Green();
    state = red ;
    break;

    case red :
    if (millis() - timer >= pausa /3) {
    state = turn_sec_yellow ;
    timer += pausa /3 ;
    }
    break;

    case turn_sec_yellow :
    secondary.Yellow();
    state = sec_yellow ;
    break;

    case sec_yellow :
    if (millis() - timer >= pausa / 3) {
    state = turn_green ;
    timer += pausa /3;
    }
    break;

    default:    // In caso di default si fa giallo lampeggiante
    led.Yellow();
    secondary.Yellow();
    delay(pausa/3);
    led.Off();
    secondary.Off();
    delay(pausa/3);
    break;

}
Serial.print(millis()); 
Serial.print(" \t Stato attuale ");
Serial.println(state);

}

/* Domande:
 1. E' agevole inserire degli altri semafori?
 2. Provare a inserire un altro semafori implementando una FSM
    separata.
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
1. Be' bisogna ragionare sul loro comportamente in rapporto alla FSM principale,   diciamo che non e' un approccio plug and play.
2. Vedi esercizio successivo.
 */
