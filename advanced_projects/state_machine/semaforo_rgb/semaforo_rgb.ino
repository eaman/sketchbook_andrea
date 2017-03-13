/*
   Semaforo RGB
   
Version: singolo semaforo + millis + memoria giallo

   Un singolo semaforo costruito col paradigma delle macchine a stato.
   Viene utilizzato un oggetto della libreria common per gestire il LED.

   Uno stimolo esterno rappresentato dalla pressione di un bottone
   causa il passaggio di stato.
   Il semaforo resta verde fino a quando non riceve lo stimolo
   (es passaggio pedonale).

   Implementata con millis() invece che con delay(),

   */

#include <common.h>
const byte input = 2; // PIN del bottone
int pausa = 3000;
long timer ;
boolean wait = 0; // Memoria bottone

enum states_available { // Stati della FMS
    green,         // Statico
    yellow,            // Statico
    red            // Statico
};

states_available state  ;


void setup() {
    pinMode(input, INPUT_PULLUP);
    Serial.begin(9600);
    timer = millis();
}

RGBLed led(11, 10, 9); 

void loop() {
    switch (state) {

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
        if (millis() - timer >= pausa /3) {
            state = red ;
            wait = 0 ;
            timer += pausa /3;
        }
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

    //Debug:
    Serial.print(millis());
    Serial.print(" \t Stato attuale ");
    Serial.print(state);
    Serial.print(" \t Wait: ");
    Serial.println(wait);

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
