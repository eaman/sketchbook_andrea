/* 
  Step
  
  Utilizzo della libreria Step
  
*/
#include <Stepper.h>
 int passi = 32 ;    // Passi del motore
 int rapporto = 64 ; // Rapporto di riduzione
// numeri di steps * rapporto di riduzione 
    // (usiamo 4 step in full step drive)

//Stepper motore(2048, 8, 10, 9, 11);
Stepper motore(passi,  8, 10, 9, 11); 


void setup() {
}

void loop()  
{
// Rotazione completa CW
  motore.setSpeed(1);   // Impostiamo la velocita'
  motore.step(4);
  delay(500);
  
  delay(1000);
  motore.setSpeed(1);   // Impostiamo la velocita'
  motore.step(-3);
  delay(500);
}
