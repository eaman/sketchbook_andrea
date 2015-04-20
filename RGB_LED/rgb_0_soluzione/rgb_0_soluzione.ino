/*
    Adafruit Arduino - Lesson 3. RGB LED
 
 RGB LED: mpostare i colori per un LED RGB
 common anode
 */

int redPin = 11;
int greenPin = 10;
int bluePin = 9;



void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{
  setColor(0xFF,0x00,0x00) ; // imposta il LED in rosso

  // setName("green") ; 
}

// Funzioni:
void setColor(int red, int green, int blue)
// Imposta i colori di un LED RGB Common Anodote
// in esadecimale
{
  analogWrite(redPin, 255 -red);
  analogWrite(greenPin, 255 - green);
  analogWrite(bluePin, 255 - blue);
}

void setName(String colorName)
// Imposta i colori di un LED RGB Common Anodote
// tramite una stringa
{
  if (colorName == "red") {
    analogWrite(redPin, 0 );
    analogWrite(greenPin, 255 );
    analogWrite(bluePin, 255 );
  } 
  else if (colorName == "green") {
    analogWrite(redPin, 255 );
    analogWrite(greenPin, 0 );
    analogWrite(bluePin, 255 );
  }
  // ...
}
/* Hints:

1. Per usare un solo valore esadecimale per settare i colori:
   - http://ardx.org/src/code/CIRC12-code-MB-SPAR.txt
 
 */







