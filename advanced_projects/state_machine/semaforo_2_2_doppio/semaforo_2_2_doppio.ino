/*
   Incrocio RGB

   Un incrocio costituito da due strade, una principale e una secondaria.
   La via viene concessa al secondario alla pressione di un bottone,
   il secondario cambia automaticamente dopo una pausa.
   Viene utilizzato un oggetto della libreria common per gestire i LED.

   Uno stimolo esterno rappresentato dalla pressione di un bottone
   causa il passaggio di stato.

   Questo sketch usa due FSM indipendenti che modificano i rispettivi stati.

- Schema per un led RGB: https://lab.piffa.net/schemi/rgb.jpg
- Schema per un bottone: https://www.arduino.cc/en/uploads/Tutorial/inputPullupButton.png
 */

#include <common.h>
const byte input = 2; // PIN del bottone
int pausa = 3000;
enum states_available { // Stati della FMS
    turn_green,    // Dinamico, transizione
    green,         // Statico
    wait_button,
    turn_red,
    red
};

states_available FSM1  ;
states_available FSM2 ;


void setup() {
  pinMode(input, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.flush();
}

RGBLed led_main(11, 10, 9); 
RGBLed led_secondary(8, 7, 6); 

void loop() {
switch (FSM1) {
    // Semaforo principale
    case turn_green :
    led_main.Green();
    FSM1 = green ; // Setta il prossimo state
    FSM2 = red ;    // Setta il prossimo state
    break;

    case green:
    delay(pausa * 2/3);
    FSM1 = wait_button ;
    break;

    case wait_button:
    if (digitalRead(input) == LOW) { 
    FSM1 = turn_red ; // Il passaggio di stato avviene alla pressione di un bottone
    };
    delay(20);
    break;

    case turn_red :
    led_main.Yellow();
    delay(pausa/3);
    led_main.Red();
    FSM1 = red ;
    FSM2 = turn_green; // Stimolo al semafor secondario
    break;

    case red :
    //delay(pausa);
    //main = turn_green ;
    break;
}

switch (FSM2) {
    // Semaforo Secondario
    case turn_green :
    led_secondary.Green();
    FSM2 = green ; // Setta il prossimo state
    break;

    case green:
    delay(pausa * 2/3);
    FSM2 = turn_red ; // Niente stimoli
    break;

    case turn_red :
    led_secondary.Yellow();
    delay(pausa/3);
    FSM1 = turn_green ;
    FSM2 = red ;
    break;

    case red :
    led_secondary.Red();
    break;
}
// Debug
Serial.print(millis()); 
Serial.print(" \t Stato attuale Main: ");
Serial.print(FSM1);
Serial.print(", secondary: ");
Serial.println(FSM2);

}
