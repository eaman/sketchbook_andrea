/* Blink without Delay
 Class: definizione di una classe LED.
 
 L'oggetto LED integra i dati (proprieta') del led con i metodi (le funzioni).
 */

// Oggetti:
class Lampeggiatore {
  // Lampeggia un LED utilizzando millis()
  // Variabili
  int ledPin ;           // il numero del LED pin
  int ledState ;         // stato attuale del LED
  long interval ;        // milliseconds di intervallo nel lampeggiare
  long previousMillis ;  // precedente cambio di stato

  // Constructor: come viene instanziato un oggetto facente parte della classe
public:
  Lampeggiatore(int pin, long time)
  {
    ledPin = pin;
    pinMode(ledPin, OUTPUT);
    ledState = LOW;
    previousMillis = 0;
    interval = time;
  }

// Una funzione facente parte di una classe prende il nome di "metodo" della stessa:
  void Update () {
    // Illumina il ledB secondo un intervallo passato come argomento

    if (millis() > previousMillis + interval) {
      // save the last time you blinked the LED 
      previousMillis = millis();   

      // if the LED is off turn it on and vice-versa:
      ledState = !ledState ; // Inverti il LED
    }
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
  
};

// Instanziamo i due led dalla classe 
Lampeggiatore ledA(13, 1000);
Lampeggiatore ledB(12, 500);

void setup() {
}

void loop()
{
ledA.Update();
ledB.Update();
}

/* Domande:
 1. Ogni quante volte viene eseguito il codice del loop per ogni millisecondo?
 2. Utilizzare un interrupt per richiamare Update()
    Es: https://learn.adafruit.com/multi-tasking-the-arduino-part-2/overview
 */

