/* Blink without Delay - Pulizia

Semplificato il ciclo condizionale
 */

// constants won't change. Used here to 
// set pin numbers:

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

////////////////
// Funzioni

void lightLedA (int interval) {
  // Illumina il ledA secondo un intervallo passato come argomento

  if(millis() - previousMillisA > interval) {
    // save the last time you blinked the LED 
    previousMillisA = millis();   

    // if the LED is off turn it on and vice-versa:
    ledStateA = !ledStateA ; // Inverti il LED
  }
  digitalWrite(ledA, ledStateA);
}

void lightLedB (int interval) {
  // Illumina il ledB secondo un intervallo passato come argomento

  if(millis() - previousMillisB > interval) {
    // save the last time you blinked the LED 
    previousMillisB = millis();   

    // if the LED is off turn it on and vice-versa:
    ledStateB = !ledStateB ; // Inverti il LED
  }
  digitalWrite(ledB, ledStateB);
}

/* Approfondimenti
 - integrazione tra funzioni e dati
 - Rapporto tra global scope e uso di pointers
 - Uso di forme di dati strutturate (array, struct) per scambiare dati tra funzioni e programma
 */











