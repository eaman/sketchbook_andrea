/* SuperCar like pattern with a shift register.
   Note: first bit/LED is supposed to be 0 and not 7
   as in many arduino example sketches.
   
 Turning on the outputs of a 74HC595 using an array
 
 Hardware:
 * 74HC595 shift register
 * LEDs attached to each of the outputs of the shift register
 */

int clockPin = 12; //IC Pin 11, Yellow Jumper
int dataPin = 11; //IC Pin 14, Blue Jumper
int latchPin = 8; //IC Pin 12, Green Jumper

byte patterns[30] = {
  B00000001, 100,
  B00000010, 100,
  B00000100, 100,
  B00001000, 100,
  B00010000, 100,
  B00100000, 100,
  B01000000, 100,
  B10000000, 100,
  B01000000, 100,
  B00100000, 100,
  B00010000, 100,
  B00001000, 100,
  B00000100, 100,
  B00000010, 100
};

int index = 0;
int count = sizeof(patterns) / 2;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, patterns[index * 2]);
  digitalWrite(latchPin, HIGH);
  delay(patterns[(index * 2) + 1]);
  index++;
  if (index >= count){
    index = 0;
  }
}

