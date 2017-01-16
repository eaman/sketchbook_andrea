/*
  Change brightness of LED linearly to Human eye
  256 step brightness using 8 bit PWM of Arduino
  with slight correction at base.
  
  https://ledshield.wordpress.com/2012/11/13/led-brightness-to-your-eye-gamma-correction-no/
  https://learn.adafruit.com/led-tricks-gamma-correction/the-quick-fix
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
   0,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,
   2,2,2,2,2,3,3,3,3,3,3,3,3,3,4,4,
   4,4,4,4,4,5,5,5,5,5,5,5,6,6,6,6,
   7,7,7,7,8,8,8,8,9,9,9,10,10,10,10,11,
   11,11,12,12,12,13,13,13,14,14,15,15,15,16,16,17,
   17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,
   25,25,26,26,27,28,28,29,29,30,31,31,32,32,33,34,
   34,35,36,37,37,38,39,39,40,41,42,43,43,44,45,46,
   47,47,48,49,50,51,52,53,54,54,55,56,57,58,59,60,
   61,62,63,64,65,66,67,68,70,71,72,73,74,75,76,77,
   79,80,81,82,83,85,86,87,88,90,91,92,94,95,96,98,
   99,100,102,103,105,106,108,109,110,112,113,115,116,118,120,121,
   123,124,126,128,129,131,132,134,136,138,139,141,143,145,146,148,
   150,152,154,155,157,159,161,163,165,167,169,171,173,175,177,179,
   181,183,185,187,189,191,193,196,198,200,202,204,207,209,211,214,
   216,218,220,223,225,228,230,232,235,237,240,242,245,248,252,255
};

int brightness = 0;             // initial brightness of LED
int fadeAmount = 1;
int led1Pin = 1;

unsigned long startTime = 0;    // timing variables
const long interval = 4;        // pause between each interval (256)


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
    if (brightness == 0 || brightness == 255)       // reverse the direction of the fading at the ends of the fade:
    {
      fadeAmount = -fadeAmount ;
    }
  }
}
