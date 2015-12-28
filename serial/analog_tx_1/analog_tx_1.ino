/*
  Analog comm: TX
 
 Comunicazione seriale tra due schede arduino.
 La prima scheda ha un bottone come input e 
 comunica con un altra scheda che monta un LED come output.
 Il led della seconda si accende quando rileva
 la pressione del bottone della prima.
 
 Schema: http://lab.piffa.net/schemi/analog_io_bb.png
 */

// Prima scheda: input
int led = 13;  // Debug
int input = 2;  // Questa e' la scheda con un input
int TX = 3 ; // Pin di trasmissione

void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);       // Il PIN e' attivato come output per DEBUG
  pinMode(TX, OUTPUT);       // Il PIN e' attivato come output
  pinMode(input, INPUT_PULLUP);        // Il PIN e' attivato come output
}

// the loop routine runs over and over again forever:
void loop() {
  if (digitalRead(input) == LOW) { // Verifica se il PIN input e' +5v
    digitalWrite(led, HIGH); // Debug
    digitalWrite(TX, HIGH);
    delay(50); // Debounce
  } 
  else { // Alterativa: se non e' +5v
    digitalWrite(led, LOW); // Debug
    digitalWrite(TX, LOW);
    delay(50);
  }
}


/* Domande:
 1. Perche' i due ground delle due schede sono collegati?
 2. Quanti LED posso pilotare con questo sistema?
 3. Con che  latenze lavoro?
 */


