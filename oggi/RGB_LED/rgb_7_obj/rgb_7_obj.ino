/*
    RGB Object

    Gestione di un LED RGB tramite programmazione a oggetti

 Schema: http://lab.piffa.net/schemi/rgb.jpg
 */

class RGBLed {
  // Classe rappresentativa di un LED RGB
  
    // Private properties, le proprieta' sono private per default
    byte redPin ;
    byte greenPin ;
    byte bluePin ;

  public:
    // Public properties
    byte redValue ;
    byte greenValue ;
    byte blueValue ;

    // Constructor: come viene instanziato un oggetto facente parte della classe
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

    void Arrossa () {
      // Metodo = funzione dell'oggetto
      // Imposta il colore di un LED RGB a rosso

      analogWrite(redPin,   0);
      analogWrite(greenPin, 255);
      analogWrite(bluePin,  255);
    }

    void SetColor (byte r, byte g, byte b) {
      // Imposta il colore di un LED RGB

      analogWrite(redPin,   r);
      analogWrite(greenPin, g);
      analogWrite(bluePin,  b);
    }
};

// Instanziamo un LED
RGBLed led(11, 10, 9);
/* L'oggetto viene istanziato qui e non nella funzione di setup()
    perche' altrimenti la sua esistenza sarebbe legata solo
    al contesto (scope) del setup(), non sarebbe disponibile nel loop()
 */

void setup()  {
  // I PIN mode vengono settati dal constructor
}

void loop() {
  led.Arrossa();
  delay(1000);
  led.SetColor(255, 0, 255) ; // Mettiamo il LED in Green
  delay(1000);

}

/* Domande
 1. Provate ad accedere (serial print oppure modificare) le proprieta private e pubbliche.

 */

