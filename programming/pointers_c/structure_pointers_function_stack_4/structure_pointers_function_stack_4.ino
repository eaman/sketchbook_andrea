

struct RGB {
  byte r;
  byte g;
  byte b;
} 
myLED ;

void setup() {    
  Serial.begin(9600);
  // Serial link to PC
}
void loop() {
  myLED = {
    100,200,255 }  
  ;

  // Serial.println(myLED.r) ;

  illumina(&myLED);
  rossa(&myLED);
  Serial.println();
  illumina(&myLED);

  Serial.flush();
  exit(0);
}

void  illumina(struct RGB *tempLED) { // Function with a pointer
  Serial.println((*tempLED).r) ; // This does not waste STACK space
  Serial.println((*tempLED).g) ; // Note: indirect operator * has lower priority
  Serial.println(tempLED->b) ; // than dot . operator , so the parentheses
                    // That is the dereference -> operator
}

struct RGB rossa(struct RGB *temp) { // Function with a pointer:
        // This can change directly the original value without the need
        // to reassign as in: myLED = rossa(myLED)
  (*temp).r = 255 ;  
  //return *temp;
}





