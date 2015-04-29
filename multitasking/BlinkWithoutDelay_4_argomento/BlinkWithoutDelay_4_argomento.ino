/* Blink without Delay
 Soluzione
 
 Introdotto un argomento per la funzione che nodifica l'intervallo di lampeggio
 
 */

// First LED
int ledA =  13;      // the number of the LED pin
// Variables will change:
int ledStateA = LOW;             // ledState used to set the LED
long previousMillisA = 0;        // will store last time LED was updated

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
  lightLedA(1000);
  lightLedB(500);
}

//////////////
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

/* Approfondimenti
- Quali similitudini ci sono tra le due funzioni?
- Come si dovrebbe fare per semplificare il codice
  evitando di ripetere larti del codice simile tra loro?
- Distinguere i dati comuni tra le due funzioni che ci servono per
  far lampeggiare i LED
- Distinguere i dati che caratterizzano un LED rispetto all'altro
*/







