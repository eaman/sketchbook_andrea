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
int ledState = 0;         // stato attuale del LED
int incomingByte;   // Dato ricevuto via seriale


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);       // Il PIN e' attivato come output

  Serial.begin(9600); // Attiviamo la seriale
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial.available() > 0) {
incomingByte = Serial.read();
    if (incomingByte == 1) { // Verifica se viene ricevuto il dato 1
      ledState = !ledState ; // Cambia lo stato del LED

      // debug
      Serial.print("I received: ");
      Serial.println(incomingByte);
    }
  }
  digitalWrite(led, ledState); // Aggiorna lo stato del LED
}

/* Domande
 Una connessione analogica permette di passare un solo tipo di segnale
 con eventuale modulazione (8bit in output da PWM e 10bit di scansione 
 come analog input).
 
 - Quanti tipi di dati permette di trasmettere la seriale?
 - Comandare un LED RGB via PWM via seriale (da una Arduino o da un PC).
 - Che caratteristiche di latenza si hanno rispetto 
 a una connessione analogica?
 - Rifare lo sketch utilizzando una STATE MACHINE: quando il
 il LED viene ACCESO / SPENTO alternativamente alla pressione
 del bottone.
 - Dove dovremo implementare il DEBOUNCE?
 - Dove implementare la gestione dello STATO?
 */



