/*
  Change brightness of LED linearly to Human eye
  32 step brightness using 8 bit PWM of Arduino
  brightness step 24 should be twice bright than step 12 to your eye.
 
  https://ledshield.wordpress.com/2012/11/13/led-brightness-to-your-eye-gamma-correction-no/
*/


#include <avr/pgmspace.h>
#define CIELPWM(a) (pgm_read_byte_near(CIEL8 + a)) // CIE Lightness lookup table function

/*
  5 bit CIE Lightness to 8 bit PWM conversion
  https://ledshield.wordpress.com/2012/11/13/led-brightness-to-your-eye-gamma-correction-no/
  L* = 116(Y/Yn)^1/3 - 16 , Y/Yn > 0.008856
  L* = 903.3(Y/Yn), Y/Yn <= 0.008856
*/

const uint8_t CIEL8[] PROGMEM = {
  0,    1,    2,    3,    4,    5,    7,    9,    12,
  15,    18,    22,    27,    32,    38,    44,    51,    58,
  67,    76,    86,    96,    108,    120,    134,    148,    163,
  180,    197,    216,    235,    255
};

int brightness = 0;  // initial brightness of LED
int fadeAmount = 1;
int led1Pin = 9;     // pause between each interval (32)

unsigned long startTime = 0;    // timing variables
const long interval = 12;


void setup()  {  
  pinMode(led1Pin, OUTPUT);     // declare pin 9 to be an output:
}

void loop()  {
  unsigned long currentTime = millis();
  if (currentTime - startTime >= interval)
  {
    startTime += interval;                         // increment timing sequence
    analogWrite(led1Pin, CIELPWM(brightness));     // set the brightness of pin 9:, 0-31, 5 bit steps of brightness
    brightness += fadeAmount;                      // change the brightness for next time through the loop:
    if (brightness == 0 || brightness == 31)       // reverse the direction of the fading at the ends of the fade:
    {
      fadeAmount = -fadeAmount ;
    }
  }
}
