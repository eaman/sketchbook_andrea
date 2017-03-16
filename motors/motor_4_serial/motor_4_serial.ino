/*
 Simple Motor:  Seriale

 Motore DC con variazione della velocita' impostata da connessione seriale

 */

const int motorPin     = 9;
int motValue   ;

void setup() {
    pinMode(motorPin, OUTPUT);
    Serial.begin(9600); // Input
    Serial.println("\t Usare valori da 0-255");
// Serial.setTimeout(2000); // Imposta il tempo di time out per la lettura
    // del buffer seriale, default = 1000ms
}

void loop() {
    if (Serial.available()) { 
        motValue = Serial.parseInt(); // leggiamo un valore da seriale
        motValue = constrain(motValue,0,255); // Limitiamo l'input dell'utente

        analogWrite(motorPin,motValue); // Change the PWM speed of the motor
        Serial.print("Velocita' motore  = ");
        Serial.println(motValue);
    }
}

/* Domande
1. Perche' il motore si resetta a zero dopo una breve pausa?
2. Come e' possibile fare in modo che il motore resti attivo
   al valore dato?
3. Da cosa e' dovuto e come e' possibile rendere il circuito piu' responsivo
  all'input dell'utente.
- Risposte a fondo pagina


























1. Perche' vede il valore di terminazione riga
  e lo scarta facendolo passare per zero
2. Impostare il monitor seriale per "Nessun fine riga"
2.1 impostare un ciclo condizionale che controlli che l'input sia composto solo da numeri
3. Impostare Serial.setTimeout per definire il tempo di lettura del buffer seriale
*/
