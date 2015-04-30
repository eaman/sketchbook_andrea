/* Blink without Delay
 Soluzione
 
 Introdotto un argomento per la funzione che nodifica l'intervallo di lampeggio 
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
  pinMode(ledA.ledPin, OUTPUT);
  pinMode(ledB.ledPin, OUTPUT);
}

void loop()
{
 ledA = lightLed(ledA );
 ledB = lightLed(ledB );
}

////////////////
// Funzioni

struct blinkLed lightLed(struct blinkLed temp) { // dataType tipo_di_struct nome_funzione(argomenti)
  // Illumina il ledA secondo un intervallo passato come argomento

  if(millis() - temp.previousMillis > temp.interval) { // gli elementi dello struct sono accessibili tramite l'operatore [punto]
    // save the last time you blinked the LED 
    temp.previousMillis = millis();   

    // if the LED is off turn it on and vice-versa:
    temp.ledState = !temp.ledState ; // Inverti il LED
  }
  digitalWrite(temp.ledPin, temp.ledState);
  return(temp); // copy by value
}



