/* Simple Motor: PWM 
 Gestine di un motore DC utilizzando il PWM
 per modificarne la velocita': ciclo ascendente e discendente
 
  Schemi:
 - Breadboard: http://lab.piffa.net/schemi/motor_transistor_diode_bb.png
 - Schema circuito: http://lab.piffa.net/schemi/motor_transistor_diode_schem.png
 
 */

int motorPin = 9; // Pin tramite cui Arduino controlla il motore
void setup() {
  pinMode(motorPin, OUTPUT);
}
void loop() {
  for(int motorValue = 0 ; motorValue <= 255; motorValue +=5){ // PWM up
    analogWrite(motorPin, motorValue);
    delay(60);
  }
  for(int motorValue = 255 ; motorValue >= 0; motorValue -=5){ // PWM down
    analogWrite(motorPin, motorValue);
    delay(30);
  }
delay(900); // Pause 
}

/* Domande
1. Il motore si muove con i valori di corrente molto bassi?
2. A quali valori comincia a muoversi effettivamente?
2.1 E per fermarsi, il valore e' diverso?
3. Impostare un valore minimo per la partenza del motore.
4. Come fare per invertire la direzione di rotazione del motore?
*/
