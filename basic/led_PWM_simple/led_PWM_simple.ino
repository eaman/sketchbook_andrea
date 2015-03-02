/*
    LED for PWM
 
 LEd PWM routine with a for loop, ascending and descending.
 
 */

int led = 11;
int c = 0;


void setup()
{
  pinMode(led, OUTPUT);

}

void loop()
{
  for ( c = 0; c < 255 ; c++) {
    analogWrite(led, c) ;
    delay(5 );
  }
  // Now reverse
    for ( c = 255; c > 0 ; c--) {
    analogWrite(led, c) ;
    delay(5 );
  }
}



