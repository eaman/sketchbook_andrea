/*
  Serial comm: TX
 
 Comunicazione seriale tra due schede arduino.
 La prima scheda ha un bottone come input e 
 comunica con un altra scheda che monta un LED come output.
 Il led della seconda si accende quando rileva
 la pressione del bottone della prima.
 
 Scema: http://lab.piffa.net/schemi/serial_common_bb.png
        http://lab.piffa.net/schemi/serial_common_schem.png
 */

// Prima scheda: input
// PIN 1 = TX
int led = 13;
int input = 2;  // Questa e' la scheda con un input

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);       // Il PIN e' attivato come output
  pinMode(input, INPUT_PULLUP);        // Il PIN e' attivato come output
  
  Serial.begin(9600); // Attiviamo la seriale
}

// the loop routine runs over and over again forever:
void loop() {
  if (digitalRead(input) == LOW) { // Verifica se il bottone e' premuto
    digitalWrite(led, HIGH);
    Serial.write(1);
    delay(50);
  } 
  else { // Alterativa: se non e' +5v
    digitalWrite(led, LOW);
    Serial.write(0);
    delay(50);
  }
}

/* Domande
Una connessione analogica permette di passare un solo tipo di segnale
con eventuale modulazione (8bit in output da PWM e 10bit di scansione 
come analog input).

1. Quanti tipi di dati permette di trasmettere la seriale?
2 Comandare un LED RGB via PWM via seriale (da una Arduino o da un PC).
2.1 Come si comportano le latenze?
2.2 C'e' perdita di segnale?
3. Rifare lo sketch utilizzando una STATE MACHINE: quando il
  il LED viene ACCESO / SPENTO alternativamente alla pressione
  del bottone.
  - Dove dovremo implementare il DEBOUNCE?
  - Dove implementare la gestione dello STATO?

Risposte in fondo:

















1. Qualunque tipo di dati, anche lunghi flussi di dati
2. Si dovra' trasmettere un segnale da 0-255 e sulla ricevente
   interpretarlo con http://www.arduino.cc/en/Reference/ParseInt
2.1 Tra buffer di trasmissione, timeout e conversione dei valori
    ci sara' una latenza nel trasferimento dei dati,
    a differenza di una connessione analigica che e' instantanea
    ma soggetta a degradazione del segnale.
2.2 Non c'e' degradazione o perdita del segnale essendo una
trasmissione di dati digitale (fin tanto che non si deteriora
la connessione).
3. Vedere lo sketch sucessivo, basandosi su gli sketch della 
    state machine per il bottne: basic/buttons/button_state_4_state_and_condition/
    
*/

