// sketch 03_01_interrupts

int ledPin = 13; 

void setup()
{
  pinMode(ledPin, OUTPUT);
  attachInterrupt(0, eventoAttivo, RISING); // 0 e' l'interrupt numero 0
      // connesso al PIN D2, l'interrupt 1 e' connesso al PIN D3
      // eventoAttivo : nome della funzione da richiamare
      // per un ISRs e' sempre VOID
      // LOW | RISING | FALLIN | CHANGE | HIGH
}

void loop()
{
  // Varie altre cose che da cui non dipende la gestione dell'interrupt
  delay(5000);
  digitalWrite(ledPin,LOW);
}

void eventoAttivo() // Sempre VOID
{
  digitalWrite(ledPin, HIGH);
}
