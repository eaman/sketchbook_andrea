/* Simple Motor
 This sketch use a transistor and a diode
 in order to poer a 5v ~150mAh directly from the board.
 Hard thing is to find a suitable motor!

 This version uses PWM for acceleration / deceleration
 */

int motorPin = 9;
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




