/*
  Serial comm: RX
 
 Comunicazione seriale tra due schede arduino.
 La prima scheda ha un bottone come input e 
 comunica con un altra scheda che monta un LED come output.
 Il led della seconda si accende quando rileva
 la pressione del bottone della prima.
 
  Scema: http://lab.piffa.net/schemi/serial_common_bb.png
        http://lab.piffa.net/schemi/serial_common_schem.png
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

1. Che differenza c'e' tra Serial.write() e Serial.print()?
2. Qual'e' il codice ASCII per indicare il numero decimale 1?
3. Servono entrambi i cavi per la connessione?
4. Potrei attaccare una terza arduino?

Links:
- http://www.arduino.cc/en/Serial/Print
- http://www.arduino.cc/en/Tutorial/ASCIITable










Risposte in fondo:
1. Vedere i links proposti: .write scrive un byte mentre
   .print manda un codice ASCII
2. 49
3. No, dato solo il cavo dalla TX alla RX .
   Provare a fare un script con comunicazione bilaterale
4. No perche' non ci sarebbe sincronia tra i segnali,
   vedere gli esercizi su I2C
*/




