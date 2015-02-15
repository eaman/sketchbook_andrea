/*
 *  Turn on / off LED with a switch.
 When the lightmode is on the LED Blinks
 */

int switchPin = 2;              // switch is connected to pin 2
int val;                        // variable for reading the pin status
int valBounce ;                 // variable for debouncing
int buttonState;                // variable to hold the last button state
int lightMode = 0;              // State of the light
int LED = 12;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);    // Set the switch pin as input
  pinMode(LED, OUTPUT);

  buttonState = digitalRead(switchPin);   // read the initial state

}


void loop(){
  val = digitalRead(switchPin);      // read input value and store it in val
  delay(10);                        // Debounce
  valBounce = digitalRead(switchPin);      // read input value and store it in val

  if ((val == valBounce) && (val != buttonState) && (val == HIGH)) {     // check if the button is pressed
    lightMode = 1 -lightMode ;    // Now with DeBounce
  }
  if (lightMode) {  // Check if light mode is TRUE == 1 or FALSE == 0
    delay(50);               // Keep the LED LOW for 50ms 
    digitalWrite(LED,HIGH);  // Blink the LED
    delay(50);               // Keep the LED HIGH for 50ms
    //  digitalWrite(LED,LOW); // We don't need to turn it LOW
                               // It will go off anyway later 
  }

  digitalWrite(LED,LOW); // Almayes turn off the LED
                         // As lightMode is FALSE == 0 turn the LED off
                         // Turn it off
  buttonState = val;                 // save the new state in our variable
}








