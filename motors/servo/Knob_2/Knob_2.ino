/* Knob

   Rotazione di un servomotore tramite un potenziometro

L'utilizzo della libreria Servo rende inutilizzabile analogWrite()
sui pin 9 e 10 dato che utilizza i timer associati a questi PIN.

Power: un servo da 9g puo' arrivare ad impegnare 750mA sotto carico
(se viene opposta resistenza al movimento del servo), un  SG90 prende 
~62mA se il movimento e' libero. Quindi in fase di test il servo puo'
essere alimentato direttamente da una scheda Arduino (200ma dal PIN 5v)
ma per l'uso finale dovra' essere alimentato autonomamente.

Schema: 
- https://www.arduino.cc/en/uploads/Tutorial/knob_bb.png
*/

// Schema: https://lab.piffa.net/schemi/potenziometro_bb.png

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
 
const int potpin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 

void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  myservo.write(val);                  // sets the servo position according to the scaled value 
  delay(15);                           // waits for the servo to get there 
} 
