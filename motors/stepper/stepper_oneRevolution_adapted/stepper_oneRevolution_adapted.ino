
/* 
 Stepper Motor Control - one revolution
 
 Revisionato per i motori 5v 28YBJ-48 con controller board
 - http://arduino-info.wikispaces.com/SmallSteppers
 
 This program drives a unipolar or bipolar stepper motor. 
 The motor is attached to digital pins 8 - 11 of the Arduino.
 
 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.  
 
  
 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe
 
 */

#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
// for your motor
//  2048 = 360deg = 32*64 in 4-step sequence as in Step Library
//  1025 = 180deg
//  512.5 = 90deg
//  5.6944 = 1deg

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution,8,10,9,11); 
// Sequence is 1-3-2-4
// Valid values:  (8,10,11,9), (9,11,8,10), (10,8,9,11), and (11,9,10,8)
// 1N1 on pin 8
// 1N2 on pin 9
// 1N3 on pin 10
// 1N4 on pin 11
// powered via 5v
// Max speed is 14RPM @ 5v

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(14); // Max speed is 14RPM @5v
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
   Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);
  
   // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500); 
}

