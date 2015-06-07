/*
  Serial comm: RX
 
 Comunicazione seriale tra due schede arduino.
 La prima scheda ha un bottone come input e 
 comunica con un altra scheda che monta un LED come output.
 Il led della seconda si accende quando rileva
 la pressione del bottone della prima.
 */

// Seconda scheda: output
// PIN 0 = RX
int led = 13; // Questa scheda ha spolo l'output

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);       // Il PIN e' attivato come output

  Serial.begin(9600); // Attiviamo la seriale
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial.read() == 1) { // Verifica se il PIN input e' +5v
    digitalWrite(led, HIGH);
    delay(50);
  } 
  else if (Serial.read() == 0) { // Alterativa: se non e' +5v
    digitalWrite(led, LOW);
    delay(50);
  }
}

/* Domande
Una connessione analogica permette di passare un solo tipo di segnale
con eventuale modulazione (8bit in output da PWM e 10bit di scansione 
come analog input).

- Quanti tipi di dati permette di trasmettere la seriale?
- Comandare un LED RGB via PWM via seriale (da una Arduino o da un PC).
*/
