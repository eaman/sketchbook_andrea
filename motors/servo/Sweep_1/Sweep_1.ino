/* Sweep

   Rotazione di un servomotore tramite la librerio Servo.h .

L'utilizzo della libreria Servo rende inutilizzabile analogWrite()
sui pin 9 e 10 dato che utilizza i timer associati a questi PIN.

Power: un servo da 9g puo' arrivare ad impegnare 750mA sotto carico
(se viene opposta resistenza al movimento del servo), un  SG90 prende 
~62mA se il movimento e' libero. Quindi in fase di test il servo puo'
essere alimentato direttamente da una scheda Arduino (200ma dal PIN 5v)
ma per l'uso finale dovra' essere alimentato autonomamente.

Schema: https://www.arduino.cc/en/uploads/Tutorial/sweep_bb.png
        http://microbotlabs.com/images/mearm-uno-servo-1.jpg
   */

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
const byte min = 10; // Ai servo economici non piace arrivare agli estremi ;)
const byte max = 170;
const int pausa = 15;
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() 
{ 
  for (pos = min; pos < max; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for (pos = max; pos >= min; pos -= 1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(pausa);                       // waits 15ms for the servo to reach the position 
  } 
} 
