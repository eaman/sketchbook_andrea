
/*
 CDROM stepper
 
 Pilotare lo step di un lettore CDROM mediante 
 il motor shield.
 
 - http://wiki.piffa.net/index.php/CNC_ROM

Pin on top, plastica sotto

    1  2    2 5 1 3   1 e' il piu' vicino al capacitor
    3  4   
    
*/

#include <AFMotor.h>

// Connect a stepper motor with 48 steps per revolution (7.5 degree)
// to motor port #2 (M3 and M4)
AF_Stepper motor(200, 2); //Motor with 200 steps per rev (1.8 degree)

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");

  motor.setSpeed(20);  // max 400 
}

void loop() {

  //motor.step(340, FORWARD, MICROSTEP); 
  //motor.step(340, BACKWARD, MICROSTEP); 
  
  for (int lenght = 340; lenght > 40; lenght -= 40)
  {
    motor.step(lenght, FORWARD, MICROSTEP);
    motor.step(lenght - 20, BACKWARD, MICROSTEP);
  }
  motor.step(150, BACKWARD, MICROSTEP);
}
