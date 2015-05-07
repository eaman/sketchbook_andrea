/*
  Interrupts : input
  
  Utilizzare un interrupt per intercettare
  l'input di un interruttore momentaneo
  
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
  state = !state;
  digitalWrite(ledPin, state);
}
