/*
HC-SR04 Ping distance sensor]
 VCC to arduino 5v GND to arduino GND
 Echo to Arduino pin 13 Trig to Arduino pin 12
 Red POS to Arduino pin 11
 Green POS to Arduino pin 10
 560 ohm resistor to both LED NEG and GRD power rail
 More info at: http://goo.gl/kJ8Gl
 Original code improvements to the Ping sketch sourced from Trollmaker.com
 Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
 */

#define trigPin 8
#define echoPin 7
#define RED 11
#define GREEN 10

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Prepare for ping
  delayMicroseconds(2); // 
  digitalWrite(trigPin, HIGH); // Send a ping
  delayMicroseconds(10); // 
  digitalWrite(trigPin, LOW); // Set down ping
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1; // Speed is ~300m/s, 
      // so it takes ~29.1 milliseconds for a cm.
      // Distance is half of (out + back)
  if (distance < 5) {  // This is where the LED On/Off happens
    digitalWrite(RED,HIGH); // When the Red condition is met, the Green LED should turn off
    digitalWrite(GREEN,LOW);
  }
  else {
    digitalWrite(RED,LOW);
    digitalWrite(GREEN,HIGH);
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}

