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
    turn_green,    // Transizione
    green,         // Statico
    wait_button,   // Evento - Stimolo
    turn_yellow,   // transizione
    yellow,        // Statico
    turn_red,      // transizione
    red            // Statico
};

states_available FSM1  ;
states_available FSM2  ;


void setup() {
  pinMode(input, INPUT_PULLUP);
  Serial.begin(9600);
  timer = millis();
}

RGBLed led1(11, 10, 9); //Istanziamo un oggetto led facente parte
RGBLed led2(8,7,6); //Istanziamo un oggetto led facente parte
                       // della classe RGBLed

void loop() {
switch (FSM1) {
    case turn_green :
    led1.Green();    
    FSM1 = green ;  // Setta il prossimo state
    FSM2 = red ;    // Setta il prossimo state
    break;

    case green:
    if (millis() - timer >= pausa * 2/3) {
    FSM1 = wait_button ;
    timer = millis(); 
    }
    break;

    case wait_button:
    if (digitalRead(input) == LOW) { 
    FSM1 = turn_yellow ; 
    timer = millis();
    delay(20); // Debouncing, si potrebbe fare con millis()
    };

    break;

    case turn_yellow :
    led1.Yellow();
    FSM1 = yellow ;
    break;

    case yellow :
    if (millis() - timer >= pausa * 2/3) {
        FSM1 = turn_red ;
        timer = millis();
    }
    break;

    case turn_red :
    led1.Red();
    FSM1 = red ;
    FSM2 = turn_green ;
    break;

    case red :
    break;

    default:    // In caso di default si fa giallo lampeggiante
    led1.Yellow();
    delay(pausa/3);
    led1.Off();
    delay(pausa/3);
    break;

}
switch (FSM2) {
    case turn_green :
    led2.Green();
    FSM2 = green ; // Setta il prossimo state
    break;

    case green:
    if (millis() - timer >= pausa * 2/3) {
    FSM2 = turn_yellow;
    timer = millis(); 
    }
    break;

    case turn_yellow :
    led2.Yellow();
    FSM2 = yellow ;
    break;

    case yellow :
    if (millis() - timer >= pausa / 3) {
    FSM2 = turn_red ;
    timer = millis(); 
    }
    break;

    case turn_red :
    FSM2 = red ;
    FSM1 = turn_green;
    break;

    case red :
    led2.Red(); // Aggiorniamo il LED in questo stato invece che nel precedente
                // per entrare nel primo ciclo di esecuzione con il LED rosso
    break;

    default:    // In caso di default si fa giallo lampeggiante
    led2.Yellow();
    delay(pausa/3);
    led2.Off();
    delay(pausa/3);
    break;
}

Serial.print(millis()); 
Serial.print(" \t Stato attuale FSM1: ");
Serial.print(FSM1);
Serial.print(" - FSM2: ");
Serial.println(FSM2);
}

/* Domande:
 1. E' piu' semplice ora inserire degli altri oggetti nello sketch?
 2. Gli eventi sono condivisi? Le varie FSM hanno modo di scambiarsi
    informazioni sui relativi stati?
 3. Creare un dispatcher degli eventi al quale le varie FSM possono
    riferirsi.
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
1. Si, per quanto le 2 FSM non siano indipendenti l'una dall'altra.
2. No, c'e' un solo flusso degli eventi, il blocco di una delle FSM 
   puo' causare lo stop di tutto il sistema.
 */
