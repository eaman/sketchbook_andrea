/* Blink without Delay
 Soluzione
 
 Introdotto un argomento per la funzione che nodifica l'intervallo di lampeggio
 
 */

// constants won't change. Used here to 
// set pin numbers:

// First LED
const int ledA =  13;      // the number of the LED pin

// Variables will change:
int ledStateA = LOW;             // ledState used to set the LED

long previousMillisA = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.


// Second LED data
int ledB = 12; //Secondo LED
int ledStateB = LOW;             // ledState used to set the LED
long previousMillisB = 0;        // will store last time LED was updated



void setup() {
  // set the digital pin as output:
  pinMode(ledA, OUTPUT);      
  pinMode(ledB, OUTPUT);  
}

void loop()
{
  lightLedA(40);
  lightLedB(500);
}


// Funzioni

void lightLedA (int interval) {
  // Illumina il ledA secondo un intervallo passato come argomento

  if(millis() - previousMillisA > interval) {
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

void lightLedB (int interval) {
  // Illumina il ledB secondo un intervallo passato come argomento

  if(millis() - previousMillisB > interval) {
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

/* TODO
- Differenze tra fuznioni e programmazione a oggetti: integrazione tra
operativita' e dati
- Rapporto tra global scope e uso di pointers
- uso di forme di dati strutturate (array, struct) per scambiare dati tra funzioni e programma
*/







