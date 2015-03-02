/*
    PWM demo with a logical analyzer
 
 Connect pin ~11 to a logic analyzer and a multimeter
 and witness the power of the built-in PWM generator.
 
 BTW: Logic comes from: http://downloads.saleae.com/betas/1.1.34/Logic+1.1.34+(64-bit).zip
 */

int led = 11;
int c = 0;


void setup()
{
  pinMode(led, OUTPUT);
  delay(5000);

}

void loop()
{  
  // Static test value, comment exit() or ad a delay()
  //analogWrite(led, 0) ; // No light
  //delay(20)
  //analogWrite(led, 254) ;  // Full light
  //delay(20)
  //analogWrite(led, 63) ;   // 1/4
  //delay(20)
  //analogWrite(led, 127) ;  // 1/2
  //delay(20)
  //analogWrite(led, 191) ;  // 3/4
  //delay(20)
  //return ;
  
  for ( c = 0; c < 255 ; c++) {
    analogWrite(led, c) ;
    delay(2 );
  }
  exit(0);

}




