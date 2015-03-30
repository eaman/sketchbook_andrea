/* Exercise 2, with a WHILE loop and a Break statement:
- http://arduino.cc/en/Reference/Break

 Test a random number agains a value: 
 a iteretive loop perform 255 runs to see if a random number in range 0-255
 is equal to the target value set to 200.
 
 Light a led in case
 Light the other LED if a run of 255 test has gone
 Log the results (if success) trough serialport
 */

// Data structure

const byte GREEN   = 13  ; // LED for found value
const byte RED     = 12 ;  // LEAD for restart

const int TARGET   = 200 ;
long randomNumber = 0L;

// Staff
const int WAIT = 1000 ;
const int REST = 10 ;
byte count = 0 ;
const byte MAXRUN = 10 ;
byte totalRun = 0 ;

void setup() {
  pinMode(RED,OUTPUT);     
  pinMode(GREEN,OUTPUT); 
  // Serial stuff
  Serial.begin(9600);
  Serial.println("Initializing random sequence, please wait for results.");
  randomSeed(analogRead(0)); // Random initializer
}

void loop() {  // put your main code here, to run repeatedly: 
  digitalWrite(GREEN, LOW);  
  digitalWrite(RED, LOW); 
  // Serial.println(count);

  while (count < 255) {
    randomNumber = random(0,255); //Randoom value generated
    Serial.print("|");
    count++ ;  
    delay(REST);
    if (randomNumber == TARGET) {  // When we catch the value
      Serial.println();
      Serial.print("--> Match found! Counter was at: "); // serial message
      Serial.println(count);
      digitalWrite(GREEN, HIGH);
      delay(WAIT);
      count++ ;
      break; // Interrompe il ciclo
    }
  }

  Serial.println();
  Serial.println("Counter resetted.");   // serial staff
  count = 0;
  digitalWrite(RED, HIGH);
  delay(WAIT);
  count++ ;
  totalRun++ ;
  if (totalRun == MAXRUN) {
    Serial.println("10 runs done, exit program.");
    digitalWrite(RED, HIGH);
    delay(WAIT);
    exit(0);
  }
} 


