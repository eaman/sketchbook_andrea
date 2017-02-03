/*
 * Interrupt doppia ISR
 * 
 * Utilizzo di un interrupt ala Arduino per intercettare
 * la pressione di un bottone.
 * 
 * Doppia ISR: la prima ISR intercetta FALLING
 * e riconfigura l'interrupt con RISING a una seconda
 * ISR che a sua volta ripristina il comportamento
 * precedente.
 */

int ledPin = 13; 

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, eventoFall, FALLING);
  // Partiamo intercettanto un interrupt FALLING
}

void loop()
{
// Tutto avviene nelle ISRs
}

void eventoFall() // Sempre VOID
{
  digitalWrite(ledPin, HIGH);
  attachInterrupt(0, eventoRise, RISING); 
}

void eventoRise() // Sempre VOID
{
  digitalWrite(ledPin, LOW);
  attachInterrupt(0, eventoFall, FALLING); 
}
