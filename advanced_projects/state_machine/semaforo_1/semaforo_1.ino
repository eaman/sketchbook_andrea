/*
   Semaforo RGB

   Un singolo semaforo costruito col paradigma delle macchine a stato.
   Viene utilizzato un oggetto della libreria common per gestire il LED.


- Schema per un led RGB: https://lab.piffa.net/schemi/rgb.jpg

   */
#include <common.h>
int pausa = 3000;
enum states_available { // Stati della FMS
    turn_green,    // Dinamico, transizione
    green,         // Statico
    turn_red,
    red
};

states_available state = red;


void setup() {
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
    state = turn_red ;
    break;

    case turn_red :
    led.Yellow();
    delay(pausa / 3);
    state = red ;
    break;

    case red :
    led.Red();
    delay(pausa);
    state = turn_green ;
    break;

    default:    // In caso di default si fa giallo
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
 1. Come legare il passaggio di stato ad un evento esterno,
    ad es. la pressione di un bottone?
 */
