/* Arduino Projects for Dummies
 * by Brock Craft 
 *
 * Chapter 4: The All-Seeing Eye
 * Sequentially lights up a series of LEDs
 *
 * v0.3 02.02.2015
 * Changed delayTime variable so that is is consistent with the 
 * text of the book. (Used to be timeDelay.)
 * v0.2 03.07.2013
 * Fixed error: timeChanged = millis(); not within if loop brackets
 */

// A variable to set a delay time between each LED
int delayTime = 50; 

// A variable to store which LED we are currently working on
int currentLED = 0;

// A variable to store the direction of travel of LEDs
int dir = 1;

// A variable to store the last time we changed something
unsigned long timeChanged = 0;

// Create an array to hold the value for each LED pin
byte ledPin[] = {
  4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void setup() {
  // Set all pins for OUTPUT  with a counter
  for (int x=0; x<10; x++) {
    pinMode(ledPin[x], OUTPUT); 
  }

  // Set all pins for OUTPUT iterating a pointer
  // byte *ptr = ledPin ;
  // while (*ptr) {
  //   pinMode(*ptr++, OUTPUT);
  // }

  // Set up the 
  timeChanged = millis();
}

void loop() {
  // Check whether it has been long enough
  if ((millis() - timeChanged) > delayTime) {
    // Turn off all of the LEDs, see next comment
    for (int x=0; x<10; x++) {
      digitalWrite(ledPin[x], LOW);
    }
    // Turning off just one LED instead on 10 would be more efficient
    // digitalWrite(ledPin[currentLED - dir], LOW);

    // Turn on the current LED
    digitalWrite(ledPin[currentLED], HIGH);

    // Increment by the direction value
    currentLED += dir;

    // If we are at the end of a row, change direction
    if (currentLED == 9) {
      dir = -1;
    }
    if (currentLED == 0) {
      dir = 1;
    }

    // Let's change the speed wit a Pot on pin A5
    // delayTime = map(analogRead(5),0,1024,20,5 00);
    // delay(2);

    // Store the current time as the time we last changed LEDs
    timeChanged = millis();
  }
}







