/*
  Manual PWM
  
  Gestire la modulazione della pulsazione tramite un delay,
  questa tecnica puo' essere usata su qualunque PIN.
  
  Altre info: http://arduino.cc/en/Tutorial/SecretsOfArduinoPWM
  */


int pausa = 5 ; // 100 e' Circa 10% del duty cicle @ 1KHz
int microPausa = 100 ; // 100 e' Circa 10% del duty cicle @ 1KHz

void setup()
{
  pinMode(13, OUTPUT); // il PIN 13 non ha il PWM in hardware
}

void loop()
{
  brilla();
// microBrilla();

}
// Funzioni personali

void brilla() {
  // lampeggia usando delay(): millesimi di secondo
  
  digitalWrite(13, HIGH);
  delay(pausa); 
  digitalWrite(13, LOW);
  delay(pausa * 5);
}

void microBrilla() {
  // lampeggia usando delayMicroseconds(): millionesimi di secondo
  
  digitalWrite(13, HIGH);
  delayMicroseconds(microPausa); 
  digitalWrite(13, LOW);
  delayMicroseconds(1000 - microPausa);
}
