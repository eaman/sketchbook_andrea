/*
   Semaforo RGB single FSM


   Doppio semaforo, una via prinicipale (led) e una secondaria (secondary):
   la via secondaria ottiene la precedenza alla pressione di un bottone.

   Implementata con millis() invece che con delay(),
   sono stati aggiuntu due stati per gestire lo stato yellow 
   del semafor secondario.

   Lo sketch e' stato implementato con una sola FSM in cui si incrociano
   gli stati dei due semafori.

- Schema per un led RGB: https://lab.piffa.net/schemi/rgb.jpg
- Schema per un bottone: https://www.arduino.cc/en/uploads/Tutorial/inputPullupButton.png
   */

#include <common.h>
const byte input = 2; // PIN del bottone
int pausa = 3000;
long timer ;
boolean wait = 0; // Memoria bottone

enum states_available { // Stati della FMS
    turn_green,    // Dinamico, transizione
    green,         // Statico
    yellow,        // Statico
    turn_red,      // Dinamico, transizione
    turn_sec_yellow,// Yellow per semaforo secondario
    sec_yellow,     // Statico
    red            // Statico
};

states_available state ;


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
        led.Green();
        if (wait && (millis() - timer >= pausa * 2/3)) {
            state = yellow;
            timer = millis();
        }

        if (digitalRead(input) == LOW) {
            wait = 1;
        }
        break;

    case yellow :
    led.Yellow();
    if (millis() - timer >= pausa / 3) {
    state = turn_red ;
    wait = 0; 
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
