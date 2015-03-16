/*
 *  Alternating switch
 */

int switchPin = 2;              // switch is connected to pin 2
int val;                        // variable for reading the pin status
int buttonState;                // variable to hold the last button state
int buttonPresses = 10;         // Counter for the button

void setup() {
  pinMode(switchPin, INPUT_PULLUP);    // Set the switch pin as input

  Serial.begin(9600);           // Set up serial communication at 9600bps
  buttonState = digitalRead(switchPin);   // read the initial state
  Serial.println("Don not press the button! :P ");
}


void loop(){
  val = digitalRead(switchPin);      // read input value and store it in val
  delay(100);                        // Debounce
  if ((val != buttonState) && (val == HIGH)) {     // check if the button is pressed
    buttonPresses-- ;
    Serial.print("Press it an other ");
    Serial.print(buttonPresses);
    Serial.println(" times.");
  }
  if (buttonPresses == 0) {
    Serial.println("----- >  ExplOdE! <------");
   // Serial.flush();                // Print out the whole serial buffer
   // exit(0);                       // Exit the sketch
  }
  buttonState = val;                 // save the new state in our variable
}


