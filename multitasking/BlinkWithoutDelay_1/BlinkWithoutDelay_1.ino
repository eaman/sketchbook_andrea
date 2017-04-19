/* Blink without Delay

 Utilizziamo la funzione millis() al posto di delay()
 per poter gestire il lampeggio di un LED senza bloccare
 il processore.

 Questo esercizio e' strutturato in una serie di passaggi incrementali
 nei quali una versione minimale si evolve per introdurre
 programmazione ad oggetti, interrupts, pointers.

Per vedere direttamente un esempio succinto:
- https://lab.piffa.net/sketchbook_andrea/basic/blinks/millis/millis.ino

Schema: https://lab.piffa.net/schemi/millis_bb.png

Tutorial:
- http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

const int ledPin =  13;

// Variabili
boolean ledState = LOW;    // Variabile associata allo stato del LED
unsigned long previousMillis = 0;  // Timestamp dell'ultimo aggiornamento,
// previousMillis dovra' essere di tipo long in quanto deve contenere numeri grandi
// e sara' sempre positiva quindi unsigned.
const unsigned long interval = 1000;  // Intervallo tra un blink e l'altro (milliseconds)
// Dato che dovra' essere aggiunta ad altre variabili long e unsigned tanto vale
// fare anche interval come quelle

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // Verifichiamo se e' il momento di modificare lo variabile
  // associata allo stato del LED.

  if (millis() - previousMillis >= interval) {
    // Timestamp + timestamp = delta temporale

    previousMillis = previousMillis + interval ;
    // Aggiorniamo il contatore previousMillis

    // Se il LED e' spento accendiamolo e vice-versa:
    if (ledState == LOW)
    {
      ledState = HIGH;
    }
    else
    {
      ledState = LOW;
    }
    // e' possibile semplificare questa operazione?
    // Hint: lo stato del LED e' binario: ha solo due stati possibili.

    // Aggiorniamo lo stato del LED
    digitalWrite(ledPin, ledState);
  }
}

/* Domande
   1. Aggioungere un LED che brilli ogni 500ms: iniziare pensando
      a quali variabili gestiscono l'attuale LED e a quali si
      dovranno aggiungere.
   2. E' ora agevole cambiare gli intervalli dei due LED?
      Modificare gli intervalli dei due led (es 500ms - 320ms)
.
.
.
.
.
.
.
.
.
.
.
   Risposta
   3. Si sarebbe introdotto uno slip (ritardo) nei tempi dello sketch

 */
