/*
  Analog comm: TX
 
 Comunicazione seriale tra due schede arduino.
 La prima scheda ha un bottone come input e 
 comunica con un altra scheda che monta un LED come output.
 Il led della seconda si accende quando rileva
 la pressione del bottone della prima.
 */

// Prima scheda: input
int led = 13;
int input = 2;  // Questa e' la scheda con un input
int TX = 3 ; // Pin di trasmissione

void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);       // Il PIN e' attivato come output
  pinMode(TX, OUTPUT);       // Il PIN e' attivato come output
  pinMode(input, INPUT);        // Il PIN e' attivato come output
}

// the loop routine runs over and over again forever:
void loop() {
  if (digitalRead(input) == HIGH) { // Verifica se il PIN input e' +5v
    digitalWrite(led, HIGH);
    digitalWrite(TX, HIGH);
    delay(50);
  } 
  else { // Alterativa: se non e' +5v
    digitalWrite(led, LOW);
    digitalWrite(TX, LOW);
    delay(50);
  }
}




