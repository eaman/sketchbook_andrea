/* Blink without Delay
 
Raggruppamento delle proprieta' dell'oggetto in uno struct.
Una funzione accetta e restituisce uno struct di questo tipo
facendo una "copy by value" (vedi esercizio con i pointers per
una "copy by reference").

Questo e' un esercizio avanzato: propedeutico a capire le basi
della programmazione a oggetti (suggerimento: 
https://lab.piffa.net/sketchbook_andrea/RGB_LED/

e' piu' semplice dato che non usa pointers e references
non dovendo modificare in modo permanente nessuna variabile
dello struct).
 */

struct blinkLed {
  // Lampeggia un LED utilizzando millis()
  // Variabili
  int ledPin ;           // il numero del LED pin
  int ledState ;         // stato attuale del LED
  long interval ;        // milliseconds di intervallo nel lampeggiare
  long previousMillis ;  //precedente cambio di stato  
} 
;

// Instanziamo i due led dalla classe 
blinkLed ledA = {
  13 , LOW , 1000, 0 };
blinkLed ledB = {
  12, LOW, 500, 0};

void setup() {
  pinMode(ledA.ledPin, OUTPUT); // Domanda: integrare l'impostazione del LED nel codice della funzione.
  pinMode(ledB.ledPin, OUTPUT);
}

void loop()
{
 ledA = lightLed(ledA ); // Aggiorna lo stato del LED in base all'esecuzione della funzione
 ledB = lightLed(ledB );
}

////////////////
// Funzioni

struct blinkLed lightLed(struct blinkLed temp) { // dataType tipo_di_struct nome_funzione(argomenti)
  // Illumina il ledA secondo un intervallo passato come argomento

  if (millis() - temp.previousMillis >= temp.interval) { // gli elementi dello struct sono accessibili tramite l'operatore [punto]
    // save the last time you blinked the LED 
    temp.previousMillis += temp.interval ;

    // if the LED is off turn it on and vice-versa:
    temp.ledState = !temp.ledState ; // Inverti il LED
  }
  digitalWrite(temp.ledPin, temp.ledState);
  return(temp); // copy by value
}



