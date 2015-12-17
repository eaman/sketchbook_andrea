/*
    Adafruit Arduino - Lesson 3. RGB LED
 
 RGB LED: mpostare i colori per un LED RGB
 common anode

 Schema: http://lab.piffa.net/schemi/rgb.jpg
 */

int redPin      = 11;   // 2v a 20ma: che resistenza dovro usare?
int greenPin    = 10;   // 3.5v a 20ma: che resistenza dovro usare?
int bluePin     = 9;    // 3.5v a 20ma: che resistenza dovro usare?



void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{
  analogWrite(redPin, 255);
  analogWrite(greenPin,255);
  analogWrite(bluePin, 255);
}

/* Domande:
 1. Come scrivere le istruzioni analog Write in modo da sottrarre i valori?
 2. Accendere il LED nei vari colori
    - http://i.stack.imgur.com/LcBvQ.gif
    Soluzione: vedi lo sketch rgb_1_all_color
 
 3. Scrivere una funzione che accetti 3 parametri per impostare i colori
 4. Scrivere una funzione che accetti come parametro il nome del colore
 es "blue" e imposti il LED.
 
 Eventuale:  
 5. Scrivere una funzione che accetti i colori in esadecimale
    - http://www.yellowpipe.com/yis/tools/hex-to-rgb/color-converter.php
 */



