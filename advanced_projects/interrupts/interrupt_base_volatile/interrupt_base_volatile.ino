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

 In questa versione le ISRs modificano una variabile state
 corrispondente allo stato del bottone, impostato nel loop.
 */

const byte ledPin = 13;
const byte interruptPin = 2; // Arduino 328 / 168
volatile boolean state = 0 ; // volatile evita che la variabile possa
// avere valori diversi in SRAM e in un registro,
// evita che il compilatore in fase di ottimizzazioe la consideri
// come const nel loop()

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP); // Vedi: digitalPinToInterrupt()
  attachInterrupt(0, eventoFall, FALLING);
  // Partiamo intercettanto un interrupt FALLING
}

void loop()
{
  digitalWrite(ledPin, state);
  // La variabile state viene richiamata fuori dalla ISR
  // quindi deve essere dichiarata volatile
// altrimenti il compilatore potrebbe decidere di trattarlo come constante
// in fase di ottimizzazione
// oppure si potrebbe creare un dualismo tra il valore di questa
// storato in SRAM o in un registro
}

void eventoFall() // Sempre VOID
{
state = HIGH ;
  attachInterrupt(0, eventoRise, RISING); 
}

void eventoRise() // Sempre VOID
{
state = LOW ;
  attachInterrupt(0, eventoFall, FALLING); 
}
