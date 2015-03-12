/*
    PWM demo with a logical analyzer
 
 Connect pin ~11 to a logic analyzer and a multimeter
 and witness the power of the built-in PWM generator.
 
 Usage: change pausa from 3000 (demostration) to 20 for sampling.
 BTW: Logic comes from: http://downloads.saleae.com/betas/1.1.34/Logic+1.1.34+(64-bit).zip
 */

int led = 9;
int pausa = 3000; // 3000 for demo or 20 when sampling


void setup()
{
  pinMode(led, OUTPUT);
  delay(3000);
}

void loop()
{  
  // Static test value, comment exit() or ad a delay()
  analogWrite(led, 1) ; // No light, just a bit
  delay(pausa);
  analogWrite(led, 63) ;   // 1/4
  delay(pausa);
  analogWrite(led, 127) ;  // 1/2
  delay(pausa);
  analogWrite(led, 191) ;  // 3/4
  delay(pausa);
  analogWrite(led, 254) ;  // Full light
  delay(pausa);
  // return ;

  for (int c = 0; c < 255 ; c++) {
    analogWrite(led, c) ;
    delay(2 );
  }
  //exit(0);

}





