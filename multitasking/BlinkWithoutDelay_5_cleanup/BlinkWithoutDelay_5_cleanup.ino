/* Blink without Delay - Pulizia

Semplificato il ciclo condizionale, la seconda funzione non necessita
di una variabile di stato per tracciare il LED.

 */

// constants won't change. Used here to 
// set pin numbers:

// First LED
const int ledA =  13;      // the number of the LED pin
// Variables will change:
int ledStateA = LOW;             // ledState used to set the LED
long previousMillisA = 0;        // will store last time LED was updated

// Second LED data
const int ledB = 12; //Secondo LED
// int ledStateB = LOW;             // Possiamo leggere lo stato del registro del LED
                                    // con digitalRead()
unsigned long previousMillisB = 0;  // millis() ritorna sempre un unsigned long

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

  if (millis() > previousMillisA + interval) {
    // save the last time you blinked the LED 
    previousMillisA = millis();   

    // if the LED is off turn it on and vice-versa:
    ledStateA = !ledStateA ; // Inverti il LED
  }
  digitalWrite(ledA, ledStateA);
}

void lightLedB (int interval) {
  // Illumina il ledB secondo un intervallo passato come argomento

  if (millis() - previousMillisB > interval) {   
    previousMillisB = millis(); 
  digitalWrite(ledB, !digitalRead(ledB));
  // Leggiamo direttamente il registro di ledB e scriviamo il suo opposto,
  // questo ci permette di non dover avere una variabile per tracciare lo stato.
  }
}
/* Domande:
 1. E' possibile avere una sola funzione che permetta di gestire 
    qualunque LED io voglia aggiungere?
    
/* Approfondimenti
 - integrazione tra funzioni e dati: programmazione a oggetti
 - Uso di pointers per modificare dati esterni allo scope della funzione, static
 - Uso di forme di dati strutturate (array, struct) per scambiare dati tra funzioni e programma
 */











