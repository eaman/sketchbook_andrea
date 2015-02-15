/*
    Adafruit Arduino - Lesson 3. RGB LED
 */

int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int c = 0;

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

void setup()
{
  pinMode(redPin, OUTPUT);

}

void loop()
{
  for ( c = 0; c < 255 ; c++) {
    analogWrite(redPin, c) ;
    delay(5 );
  }
}


