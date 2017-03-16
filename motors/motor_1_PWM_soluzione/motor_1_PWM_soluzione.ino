/* Simple Motor: PWM Soluzione

 Motore DC con variazione della velocita' tramite PWM
 
  Schemi:
 - Breadboard: http://lab.piffa.net/schemi/motor_transistor_diode_bb.png
 - Schema circuito: http://lab.piffa.net/schemi/motor_transistor_diode_schem.png
 
 */

int motorPin = 9;
int minValue = 60;  // Valore minimo per far partire il motore da fermo
void setup() {
  pinMode(motorPin, OUTPUT);
}
void loop() {
  for(int motorValue = minValue ; motorValue <= 255; motorValue +=5){ // PWM up
    analogWrite(motorPin, motorValue);
    delay(60);
  }
  for(int motorValue = 255 ; motorValue >= 30; motorValue -=5){ // 
  // Quando il motore e' in movimento puo' muoversi fino a un valore piu' basso
  // di minVal
    analogWrite(motorPin, motorValue);
    delay(30);
  }
analogWrite(motorPin, 0); // Fermiamo il motore per sicurezza
delay(900); // Pause 
}

/* Domande
1. Il motore si muove con i valori di corrente molto bassi?
2. A quali valori comincia a muoversi effettivamente?
2.1 E per fermarsi, il valore e' diverso?
3. Impostare un valore minimo per la partenza del motore.
4. Come fare per invertire la direzione di rotazione del motore?

  Risposte:
4. Basta invertire la polarita' dei cavi che vanno al motore
*/

