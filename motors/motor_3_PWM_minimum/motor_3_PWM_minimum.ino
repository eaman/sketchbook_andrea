/* 
  Simple Motor : Potenziometro con minimo
  
 Motore DC con variazione della velocita' impostata 
 tramite un potenziometro 10k ohms,
 settato un valore minimo sotto il quale il motore
 non viene attivato.
 
 Schema: http://lab.piffa.net/schemi/motor_pot_bb.png
 
 */

const int analogInPin  = A0; // Pin a cui e' collegato il potenziometro
const int motorPin     = 9;

int potValue     = 0;
int motValue   = 0;
const int minMotValue = 50 ; // Valore minimo per il motore,
            // questo variera' in base ai motori
            
void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600); // Debuggin

}
void loop() {
  potValue = analogRead(analogInPin); 
  motValue = potValue / 4 ; // mappatura 1024 -> 255

if (motValue > minMotValue) { // Minimum motor spped check
  analogWrite(motorPin,motValue); // Imposta la velocita' del motore
} else {
analogWrite(motorPin,LOW) ;
}

  
  Serial.print("Pot value = " );                       
  Serial.print(potValue);      
  Serial.print("\t Motore velocita' = ");      
  Serial.println(motValue); 
  delay(3); // Pausa, aiuta a stabilizzare l'input

}
