/* 
 Simple Motor with variable spped from pot input
 
 This sketch use a transistor and a diode
 in order to poer a 5v ~150mAh directly from the board.
 Hard thing is to find a suitable motor!
 
 This version uses a pot as throttle control,
 serial for debuggin.
 */

const int analogInPin  = A0;
const int motorPin     = 9;

int potValue     = 0;
int motValue   = 0;

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600); // Debuggin

}
void loop() {
  potValue = analogRead(analogInPin); 
  motValue = potValue / 4 ; // Simple mapping 1024 -> 255

  analogWrite(motorPin,motValue); // Change the PWM speed of the motor

  Serial.print("Pot value = " );                       
  Serial.print(potValue);      
  Serial.print("\t Motor speed = ");      
  Serial.println(motValue); 
  delay(3); // Pause, helps to stabilize the input
            // and keeps a brushed motor from over heating ;) 
}






