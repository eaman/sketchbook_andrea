/*
   Semaforo RGB

   Un singolo semaforo costruito col paradigma delle macchine a stato.
   Viene utilizzato un oggetto della libreria common per gestire il LED.

   Uno stimolo esterno rappresentato dalla pressione di un bottone
   causa il passaggio di stato.

   Implementata con millis() invece che con delay(),
   sono stati aggiuntu due stati per meglio gestire lo stato yellow.

- Schema per un led RGB: https://lab.piffa.net/schemi/rgb.jpg
- Schema per un bottone: https://www.arduino.cc/en/uploads/Tutorial/inputPullupButton.png
   */

#include <common.h>
const byte input = 2; // PIN del bottone
int pausa = 3000;
long timer ;
enum states_available { // Stati della FMS
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

case green:
    led.Green();
    if (millis() - timer >= pausa * 2/3) {
        state = wait_button ;
        timer += pausa * 2/3 ;
    }
    break;

case wait_button:
    if (digitalRead(input) == LOW) {
        state = turn_yellow ; // Il passaggio di stato avviene alla pressione di un bottone
        delay(20); // Debouncing, si potrebbe fare con millis()
        timer = millis();
    };
    break;

case turn_yellow :
    state = yellow ;
    break;

case yellow :
    led.Yellow();
    if (millis() - timer >= pausa / 3) {
        state = turn_red ;
        timer += pausa  / 3;
    }
    break;

case turn_red :
    state = red ;
    break;

case red :
    led.Red();
    if (millis() - timer >= pausa) {
        state = green ;
        timer += pausa ;
    }
    break;

default:    // In caso di default si fa giallo lampeggiante
    led.Yellow();
    delay(pausa/3);
    led.Off();
    delay(pausa/3);
    break;

}
// Debug:
Serial.print(millis());
Serial.print(" \t Stato attuale ");
Serial.println(state);

}

/* Domande:
 1. Fare in modo che nello stato verde venga recepito un'eventuale pressione
 del bottone, venga comunque garantito un periodo minimo per il verde ma nel caso
 sia stato premuto il bottone durante questo si passi poi direttamente al giallo.
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
1. Vedi esercizio: semaforo_rgb
 */
