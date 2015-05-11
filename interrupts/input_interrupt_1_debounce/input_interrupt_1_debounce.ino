/*
  Interrupts : input deboounce
 
 Utilizzare un interrupt per intercettare
 l'input di un interruttore momentaneo.
 
 Debounce software nella funzione richiamata.
 Per debounce hardware: http://www.all-electric.com/schematic/debounce.htm
 
 */

int ledPin = 13;
volatile int state = LOW;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, blink, FALLING);
}

void loop()
{
  //digitalWrite(ledPin, state);
  delay(10000); // Mette in pausa Arduino per 10sec
}

// Funzioni
void blink()
// Modifica dello stato del LED
{
  static unsigned long last_interrupt_time = 0;
  // If interrupts come faster than 200ms, assume it's a bounce and ignore
  if (millis() - last_interrupt_time > 200)
  { // Azione da intraprendere
    state = !state;
    digitalWrite(ledPin, state);
  }
  last_interrupt_time = millis();
}

