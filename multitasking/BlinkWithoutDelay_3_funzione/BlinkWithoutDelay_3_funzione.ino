/* Blink without Delay: Refactoring
 
 Blink con funzione
 
 Soluzione: Provare a isolare il codice per accendere ogni singolo led in una funzione:
 
    - Quali variabili determinano il comportamento del LED?
    - Come cambiano durante il corso dello script?
    - Sono globali o locali? 

Variabili: http://www.maffucci.it/2011/12/15/appunti-di-programmazione-su-arduino-variabili/ 

 */

/////////////
// First LED
const int ledA =  13;       // the number of the LED pin
int ledStateA = LOW;        // ledState used to set the LED
long previousMillisA = 0;   // will store last time LED was updated
long intervalA = 1000;      // interval at which to blink (milliseconds)
void lightLedA () ;

//////////////
//  Second LED
// Ora con meno variabili globali utilizzando static (vedi corpo della funzione)
const int ledB = 12; //Secondo LED
long previousMillisB = 0;    // will store last time LED was updated
                             // interval at which to blink (milliseconds)
void lightLedB () ;


void setup() {
  // set the digital pin as output:
  pinMode(ledA, OUTPUT);      
  pinMode(ledB, OUTPUT);  
}

void loop()
{
  lightLedA();
  lightLedB();
}


// Funzioni:

void lightLedA () {
  if (millis() - previousMillisA >=  intervalA) {
    // save the last time you blinked the LED 
    previousMillisA += intervalA;

    // if the LED is off turn it on and vice-versa:
      ledStateA = !ledStateA ;
    // set the LED with the ledState of the variable:
    digitalWrite(ledA, ledStateA);
  }

}

void lightLedB () {
  long intervalB = 500;
   static int ledStateB ;  // https://www.arduino.cc/en/Reference/Static
  if (millis() - previousMillisB >= intervalB) {
    // save the last time you blinked the LED 
    previousMillisB += intervalB ;

    // if the LED is off turn it on and vice-versa:
      ledStateB = !ledStateB;
    // set the LED with the ledState of the variable:
    digitalWrite(ledB, ledStateB);
  }
}


/* Domande
 1. Modificare le funzioni in modo che accettino come parametro
 l'intervallo di lampeggio.
 
 */






