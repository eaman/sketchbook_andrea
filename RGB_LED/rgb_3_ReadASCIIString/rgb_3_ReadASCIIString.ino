/*
  Reading a serial ASCII-encoded string.
  
  Beware: set monitor to NL NewLine only
 
 This sketch demonstrates the Serial parseInt() function.
 It looks for an ASCII string of comma-separated values.
 It parses them into ints, and uses those to fade an RGB LED.
 

 
 Once you have programmed the Arduino, open your Serial minitor. 
 Make sure you have chosen to send a newline character when sending a message. 
 Enter values between 0-255 for the lights in the following format : 
 Red,Green,Blue. 

 Seriously: did you set the Newline setting in the monitor?

 
 Once you have sent the values to the Arduino, 
 the attached LED will turn the color you specified, 
 and you will receive the HEX values in the serial monitor. 
 
 created 13 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.



  Schema: http://lab.piffa.net/schemi/rgb.jpg

 */

// pins for the LEDs:
const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    int red = Serial.parseInt();
    // do it again:
    int green = Serial.parseInt();
    // do it again:
    int blue = Serial.parseInt();

    // look for the newline. That's the end of your
    // sentence:
    if (Serial.read() == '\n') {
      // constrain the values to 0 - 255 and invert
      // if you're using a common-cathode LED, just use "constrain(color, 0, 255);"
      red = 255 - constrain(red, 0, 255);
      green = 255 - constrain(green, 0, 255);
      blue = 255 - constrain(blue, 0, 255);

      // fade the red, green, and blue legs of the LED:
      analogWrite(redPin, red);
      analogWrite(greenPin, green);
      analogWrite(bluePin, blue);

      // print the three numbers in one string as hexadecimal:
      Serial.print(red, HEX);
      Serial.print(green, HEX);
      Serial.println(blue, HEX);
    }
  }
}
