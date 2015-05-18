/* Simple Motor

Gestione di un motore DC tramite Arduino.
Elementi richiesti:

- motore DC a 5v per ~300ma
- transistor NPN 2N2222
- diodo 1N4001
 
 Schemi:
 - Breadboard: http://lab.piffa.net/schemi/motor_transistor_diode_bb.png
 - Schema circuito: http://lab.piffa.net/schemi/motor_transistor_diode_schem.png
 
 */

int motorPin = 9; // Pin tramite cui Arduino controlla il motore
void setup() {
  pinMode(motorPin, OUTPUT); 
}

void loop() {
  digitalWrite(motorPin, HIGH); // Accende il motore a tutta potenza
  delay(1000);
  digitalWrite(motorPin, LOW);  // Spegne il motore
  delay(5000);
}



