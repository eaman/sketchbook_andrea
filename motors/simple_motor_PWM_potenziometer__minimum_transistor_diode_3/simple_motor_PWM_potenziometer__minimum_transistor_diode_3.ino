/* 
 Simple Motor with variable spped from pot input
 
 This sketch use a transistor and a diode
 in order to poer a 5v ~150mAh directly from the board.
 Hard thing is to find a suitable motor!


  This version uses a pot as throttle control,
 serial for debuggin.

 Optimized for a minimum throttle value in order to keep the motor off
 */

const int analogInPin  = A0;
const int motorPin     = 9;

int potValue     = 0;
int motValue   = 0;
const int minMotValue = 50 ; // Minimum power requiement of my own motr,
            // This is going to differ from motor to motor
            
void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600); // Debuggin

}
void loop() {
  potValue = analogRead(analogInPin); 
  motValue = potValue / 4 ; // Simple mapping 1024 -> 255

if (motValue > minMotValue) { // Minimum motor spped check
  analogWrite(motorPin,motValue); // Change the PWM speed of the motor
} else {
analogWrite(motorPin,LOW) ;
}

  
  Serial.print("Pot value = " );                       
  Serial.print(potValue);      
  Serial.print("\t Motor speed = ");      
  Serial.println(motValue); 
  delay(3); // Pause, helps to stabilize the input, 
            // slows the serial output
}






