/* Blink without Delay - due led

 Utilizziamo la funzione millis() al posto di delay()
 per poter gestire il lampeggio di un LED senza bloccare
 il processore.

 Questo esercizio e' strutturato in una serie di passaggi incrementali
 nei quali una versione minimale si evolve per introdurre
 programmazione ad oggetti, interrupts, pointers.

Schema: https://lab.piffa.net/schemi/millis_bb.png

 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

// constants won't change. Used here to
// set pin numbers:
const int ledA = 13;      // Primo LED
const int ledB = 12;      // Secondo LED

// Variabbili di stato
int ledStateA = LOW;             // ledState used to set the LED
int ledStateB = LOW;             // ledState used to set the LED

unsigned long previousMillisA = 0;        // Timestamp dell'ultimo aggiornamento
unsigned long previousMillisB = 0;        // Timestamp dell'ultimo aggiornamento

long intervalA = 1000;           // interval at which to blink (milliseconds)
long intervalB = 500;            // interval at which to blink (milliseconds)

void setup() {
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop()
{
  // Primo LED
  if (millis() - previousMillisA >= intervalA) {
    // Aggiornimo il riferimento temporale
    previousMillisA += intervalA;

    // Se il LED e' spento accendiamolo e vice-versa:
    if (ledStateA == LOW)
      ledStateA = HIGH;
    else
      ledStateA = LOW;
    digitalWrite(ledA, ledStateA);
  }

  // Secondo LED
  if (millis() >= previousMillisB + intervalB) {
    // save the last time you blinked the LED
    previousMillisB += intervalB;
    // Se il LED e' spento accendiamolo e vice-versa:
    if (ledStateB == LOW)
      ledStateB = HIGH;
    else
      ledStateB = LOW;
    // e' possibile semplificare questa operazione?
    // Hint: lo stato del LED e' binario: ha solo due stati possibili.
    
    digitalWrite(ledB, ledStateB);
  }
}

/* Domande
 1. Cercare di semplificare / ripulire il codice.
 
 */



