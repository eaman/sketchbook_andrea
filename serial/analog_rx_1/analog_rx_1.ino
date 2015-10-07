/*
  Analog comm: RX
 
 Comunicazione analogica tra due schede arduino.
 La prima scheda ha un bottone come input e 
 comunica con un altra scheda che monta un LED come output.
 Il led della seconda si accende quando rileva
 la pressione del bottone della prima.
 
 Schema: http://lab.piffa.net/schemi/analog_io_bb.png
 */

// Seconda scheda: output
int led  = 13; // Questa scheda ha spolo l'output
int RX   = 3 ; // Pin di ricezione  

void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);       // Il PIN e' attivato come output
  pinMode(RX, INPUT);        // Il PIN e' attivato come output
}

// the loop routine runs over and over again forever:
void loop() {
  if (digitalRead(RX) == 1) { // Verifica se il PIN input e' +5v
    digitalWrite(led, HIGH);
    delay(50);
  } 
  else if (digitalRead(RX) == 0) { // Alterativa: se non e' +5v
    digitalWrite(led, LOW);
    delay(50);
  }
}

