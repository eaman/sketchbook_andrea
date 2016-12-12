/*
    RGB Array 

 RGB LED: impostare i colori per un LED RGB
 common anode tramite array

 Schema: http://lab.piffa.net/schemi/rgb.jpg
 */

byte pin[3]   = {11, 10, 9};   // 2v a 20ma: che resistenza dovro usare?
byte color[3] = {255, 255, 255};



void setup()
{
  for (byte i = 0; i < 4; i++) {
    pinMode(pin[i], OUTPUT);
  }
}


void loop()
{
  analogWrite(pin[0], color[0]);
  analogWrite(pin[1], color[1]);
  analogWrite(pin[2], color[2]);
}

/* Domande:
 1. Che differenza c'e' tra le variabili dei pin e dei colori?
 */



