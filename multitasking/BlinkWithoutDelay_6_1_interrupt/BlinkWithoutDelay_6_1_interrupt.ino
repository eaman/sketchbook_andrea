/* Blink without Delay

 Utilizzo di un interrupt per richiamare update()
 una volta ogni millesimo di secondo
 */

// Oggetti:
class Lampeggiatore {
  // Lampeggia un LED utilizzando millis()
  // Variabili
  int ledPin ;           // il numero del LED pin
  int ledState ;         // stato attuale del LED
  long interval ;        // milliseconds di intervallo nel lampeggiare
  long previousMillis ;  //precedente cambio di stato

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
  // Interrupt ogni millesimo di secondo
  // Timer0 is already used for millis() - we'll just interrupt somewhere
  // in the middle and call the "Compare A" function below
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
}
// A ogni millisecondo l'interrupt attiva questa funzione
SIGNAL(TIMER0_COMPA_vect) 
{ 
  ledA.Update();
  ledB.Update();
} 
void loop()
{
  // Gli aggiornamenti dei LED ora vengono richiamati dalla funzione
  // associata agli interrupt
//  ledA.Update();
//  ledB.Update();
}



