/*
   Interrupt base
   
   Utilizzo di un interrupt ala Arduino per intercettare
   la pressione di un bottone.

   Un momentary switch e' collegato in PULL UP al PIN D2
   La Interrupt Service Routine reazioneISR viene associata all'interrupt 0
   che reagisce al passaggio di stato 5v -> 0v del PIN D2

   La pressione del bottone causa l'accensione del bottone
   che viene spento periodicamente ogni 3 secondi nel loop,
   il delay non pregiudica la percezione dell'evento.

Schema: https://www.arduino.cc/en/uploads/Tutorial/inputPullupButton.png
   
 */

int ledPin = 13; 

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, reazioneISR, FALLING); // 0 e' l'interrupt numero 0
      // connesso al PIN D2, l'interrupt 1 e' connesso al PIN D3
      // eventoAttivo : nome della funzione da richiamare
      // per un ISRs e' sempre VOID
      // LOW | RISING | FALLIN | CHANGE | HIGH
}

void loop()
{
  // Varie altre cose che da cui non dipende la gestione dell'interrupt
  delay(3000);
  digitalWrite(ledPin,LOW);
}

void reazioneISR() // Sempre VOID
{
  digitalWrite(ledPin, HIGH);
}
