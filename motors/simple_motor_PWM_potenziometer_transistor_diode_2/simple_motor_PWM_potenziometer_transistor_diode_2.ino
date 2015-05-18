/* 
 Simple Motor : Potenziometro
 
 Motore DC con variazione della velocita' impostata 
 tramite un potenziometro 10k ohms
 
 Schema: http://lab.piffa.net/schemi/motor_pot_bb.png
 */

const int analogInPin  = A0; // Pin a cui e' collegato il potenziometro
const int motorPin     = 9;

int potValue     = 0;
int motValue   = 0;

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600); // Debuggin

}
void loop() {
  potValue = analogRead(analogInPin); 
  motValue = potValue / 4 ; //mappatura 1024 -> 255

  analogWrite(motorPin,motValue); // Imposta la velocita' del motore

  Serial.print("Pot value = " );                       
  Serial.print(potValue);      
  Serial.print("\t Motore velocita' = ");      
  Serial.println(motValue); 
  delay(3); // Pausa, aiuta a stabilizzare l'input
           
}

/* Domande

1. Cosa succede quando il motore ha riceve un carico molto basso?
2. Impostare un valore minimo per la partenza del motore, 
   sotto al quale il motore non parte.
*/



