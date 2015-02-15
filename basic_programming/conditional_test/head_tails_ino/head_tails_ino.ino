/*
  Head tails
  Generates a random number in order to simulate a coin toss.


  Phisical LEDS and serial debug.
 
 This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
const int head   = 13  ; // LED for HEAD
const int tail   = 12 ;  // LEAD for Tails
const int PAUSE  = 1000 ;
const int REST   = 50 ;
long randomNumber = 0L; // Use the "L" to tell compiler it's a long data type, not an int.
int hCount = 0;
int tCount = 0;
int runs   = 0 ;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(head, OUTPUT);     
  pinMode(tail, OUTPUT);     
  randomSeed(analogRead(0)); // Random initializer
  Serial.begin(9600);
  Serial.println("Initializing random sequence, please wait for results.");
}

// the loop routine runs over and over again forever:
void loop() {
  randomNumber = random();
  digitalWrite(head, LOW);  
  digitalWrite(tail, LOW); 
  delay(REST);   // wait a bit
  if (randomNumber % 2 == 1) {
    digitalWrite(head, HIGH);// turn the LED on ON
    hCount++ ;
  } 
  else {
    digitalWrite(tail, HIGH);// turn the LED ON
    tCount++ ;
  }

  delay(PAUSE);               // Long pause
  runs++;
  
  if (runs % 10 == 0) {  // Each 10 runs print a summary to serial
    Serial.print("Results after more 10 runs, for a total of: ");
    Serial.println(runs);
    Serial.print("Tails: \t") ;
    Serial.println(tCount);
    Serial.print("Heads: \t");
    Serial.println(hCount);
  } 
}



