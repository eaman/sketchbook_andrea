/* 
 Simple Motor: Pot - Soluzione
 
 Motore DC con variazione della velocita' tramite PWM
 pilotata da un potenziometro
 
 Impostare una mappatura in modo che il motore parta 
 da un valore minimo adeguato.
 
 */

const int analogInPin  = A0;
const int motorPin     = 9;

int potValue   = 0;
int motValue   = 0;

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600); // Debuggin

}
void loop() {
  potValue = analogRead(analogInPin) ; 
  motValue =  potValue / 4 ;// Mappatura semplificata da 1024 -> 255

// Debug
  Serial.print("Pot value = " );                       
  Serial.print(potValue);      
  Serial.print("\t Motor speed = ");      
  Serial.println(motValue); 
  
  if (motValue > 60) { // Valore minimo per far partire il motore
    analogWrite(motorPin,motValue); // 
  } 
  else analogWrite(motorPin,0); // Se non supera il valore minimo 
  // deve restare fermo

  delay(3); // Pause, stabilizza la lettura del Pot           
}

