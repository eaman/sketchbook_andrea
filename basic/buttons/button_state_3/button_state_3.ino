/*
 *  Alternating switch
 */

int switchPin = 2;              // switch is connected to pin 2
int val;                        // variable for reading the pin status
int buttonState;                // variable to hold the last button state

void setup() {
  pinMode(switchPin, INPUT);    // Set the switch pin as input

  Serial.begin(9600);           // Set up serial communication at 9600bps
  buttonState = digitalRead(switchPin);   // read the initial state
}


void loop(){
  val = digitalRead(switchPin);      // read input value and store it in val

  if (val != buttonState) {          // the button state has changed!
    if (val == LOW) {                // check if the button is pressed
      Serial.println("Button just pressed");
    } else {                         // the button is -not- pressed...
      Serial.println("Button just released");
    }
  }

  buttonState = val;                 // save the new state in our variable
}
