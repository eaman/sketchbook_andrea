/* Simple Motor
 This sketch use a transistor and a diode
 in order to power a 5v ~150mAh directly from the board.
 Hard thing is to find a suitable motor!

 In order to power a more powerfull motor you need to connect
 the transistor to an other power line. 
 */

int motorPin = 9;
void setup() {
  pinMode(motorPin, OUTPUT); // We drive the motor just like a LED
}

void loop() {
  digitalWrite(motorPin, HIGH); // Turn on the motor full throttle
  delay(1000);
  digitalWrite(motorPin, LOW);  // Turn off motor
  delay(5000);
}



