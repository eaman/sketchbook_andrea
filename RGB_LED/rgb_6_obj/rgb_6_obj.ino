/*
    Adafruit Arduino - Lesson 3. RGB LED

 RGB LED: mpostare i colori per un LED RGB
 common anode

 Schema: http://lab.piffa.net/schemi/rgb.jpg
 */

class RGBLed {
    const byte redPin ;
    const byte greenPin ;
    const byte bluePin ;
    byte redValue ;
    byte greenValue ;
    byte blueValue ;

    // Constructor: come viene instanziato un oggetto facente parte della classe
  public:
    RGBLed(byte pinR, byte pinG, byte pinB)
    {
      // Carichiamo i valori dei PIN dentro alle proprieta'
      redPin    = pinR ;
      greenPin  = pinG ;
      bluePin   = pinB ;

      // Equvalente del Setup() per inizializzare i PIN
      pinMode(redPin, OUTPUT);
      pinMode(greenPin, OUTPUT);
      pinMode(greenPin, OUTPUT);
    }

    void Color (byte r, byte g, byte b) {
      // Imposta il colore di un LED RGB
      byte redValue   = r;
      byte greenValue = g;
      byte blueValue  = b;

      analogWrite(redPin,   redValue);
      analogWrite(greenPin, greenValue);
      analogWrite(bluePin,  blueValue);
    }
};

// Instanziamo un LED
RGBLed led(11, 10, 9); 
/* L'oggetto viene istanziato qui e non nella funzione di setup()
 *  perche' altrimenti la sua esistenza sarebbe legata solo 
 *  al contesto (scope) del setup(), non sarebbe disponibile nel loop()
 */

void setup()  {
      // I PIN mode vengono settati dal constructor    
      }


void loop(){
led.Color(0,255,255) ; // Mettiamo il LED in Rosso
    }
