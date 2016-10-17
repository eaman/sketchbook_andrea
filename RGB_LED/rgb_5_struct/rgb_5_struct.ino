/*
    RGB struct LED

 RGB LED: mpostare i colori per un LED RGB
 common anode utilizzando uno struct

 Schema: http://lab.piffa.net/schemi/rgb.jpg
 */

byte pin[3]   = {11, 10, 9};   // 2v a 20ma: che resistenza dovro usare?

struct color {
  byte red ;
  byte blue;
  byte green;

} ;

color led;


void setup()
{
  for (byte i = 0; i < 4; i++) {
    pinMode(pin[i], OUTPUT);
  }
}


void loop()
{
  analogWrite(pin[0], led.red);
  analogWrite(pin[1], led.green);
  analogWrite(pin[2], led.blue);
}

/* Domande:
 1. Potrei mettere i numeri dei PIN dentro lo stesso struct?
 2. Quale differenza funzionale c'e' tra i numeri dei PIN e i colori?
 2.1 Quando devo settare i pin e quante volte?
 2.2 Quando imposto i colori e quanto spesso?

 3. Sarebbe piu' elegante scrivere una funzione per gestire il setup dei PIN
 e impostare i colori?
 3.1 Servira' una o piu' funzioni?
 4. Esiste un costrutto che mi permetta di legare le differenti caratteristiche
 del LED RGB e contemporaneamente raggruppare le funzioni che tipicamente uso con questo?
 */


/* Risposte:
 *  1.

struct ledRGB {
    byte r;
    byte g;
    byte b;
    byte    blue;
    byte    green;
    byte    red;
};

ledRGB led {0,255,255,9,10,11};
   
   

void setup()
{
  pinMode(led.blue, OUTPUT);
  pinMode(led.green, OUTPUT);
  pinMode(led.red, OUTPUT);
}

void loop()
{
  analogWrite(led.red,led.r );
  analogWrite(led.green,led.g);
  analogWrite(led.blue,led.b);
}
*/
 */
