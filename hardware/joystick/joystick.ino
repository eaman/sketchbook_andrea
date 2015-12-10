/* Joystick
Utilizzo di un joystick analogico con arduino.
da: http://42bots.com/tutorials/arduino-joystick-module-example/

Il joystich ha 2 potenziometri analogici e un interruttore digitale
corrispondente alla pressione dello stick (input momentaneo).
 
 */
int xPin = A1;
int yPin = A0;
int buttonPin = 2;

int xPosition = 0;
int yPosition = 0;
int buttonState = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  //activate pull-up resistor on the push-button pin
  pinMode(buttonPin, INPUT_PULLUP); 
  
  // For versions prior to Arduino 1.0.1
  // pinMode(buttonPin, INPUT);
  // digitalWrite(buttonPin, HIGH);
  
}

void loop() {
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  buttonState = digitalRead(buttonPin);
  
  Serial.print("X: ");
  Serial.print(xPosition);
  Serial.print(" | Y: ");
  Serial.print(yPosition);
  Serial.print(" | Button: ");
  Serial.println(buttonState);

  delay(100); // add some delay between reads
}