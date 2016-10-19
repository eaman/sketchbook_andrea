/* Blink without Delay
 
 Blink con funzione
 
 Soluzione: Provare a isolare il codice per accendere ogni singolo led in una funzione:
 
    - Quali variabili determinano il comportamento del LED?
    - Come cambiano durante il corso dello script?
    - Sono globali o locali? 
 
 */

/////////////
// First LED
const int ledA =  13;      // the number of the LED pin
// Variables will change:
int ledStateA = LOW;             // ledState used to set the LED
long previousMillisA = 0;        // will store last time LED was updated
// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long intervalA = 1000;           // interval at which to blink (milliseconds)
void lightLedA () ;

//////////////
//  Second LED
// Now with less global variables thanks to static (see function body)
const int ledB = 12; //Secondo LED
           // ledState used to set the LED
long previousMillisB = 0;        // will store last time LED was updated
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
  if (millis() > previousMillisA + intervalA) {
    // save the last time you blinked the LED 
    previousMillisA = millis();   

    // if the LED is off turn it on and vice-versa:
    if (ledStateA == LOW)
      ledStateA = HIGH;
    else
      ledStateA = LOW;
    // set the LED with the ledState of the variable:
    digitalWrite(ledA, ledStateA);
  }

}

void lightLedB () {
  long intervalB = 500;
   static int ledStateB ;  // https://www.arduino.cc/en/Reference/Static
  if (millis() > previousMillisB + intervalB) {
    // save the last time you blinked the LED 
    previousMillisB = millis();   

    // if the LED is off turn it on and vice-versa:
    if (ledStateB == LOW)
      ledStateB = HIGH;
    else
      ledStateB = LOW;
    // set the LED with the ledState of the variable:
    digitalWrite(ledB, ledStateB);
  }
}


/* Domande
 1. Modificare le funzioni in modo che accettino come parametro
 l'intervallo di lampeggio.
 
 */






