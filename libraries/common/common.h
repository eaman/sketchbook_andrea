/*
  Common Class

  Collezione di funzioni e oggetti comuni incontrati durante
  i vari esercizi.

  Header file
  Contiene i prototipi delle funzioni e degli oggetti,
  il codice e' nel fine *.cpp

*/

#include "Arduino.h"
#ifndef common_h // Questi cicli IF, gestiti come macro da preprocessor
#define common_h // fanno si che questo file non venga incluso piu' volte


/////////////////////////////////////////////
class RGBLed {
  // Classe rappresentativa di un LED RGB
  
    byte redPin ;
    byte greenPin ;
    byte bluePin ;
    byte redValue ;
    byte greenValue ;
    byte blueValue ;

  public:
    RGBLed (byte pinR, byte pinG, byte pinB) ;
	void Red ();
    void Green ();
    void Blue ();
    void Magenta ();
    void Cyano ();
    void White ();
    void Yellow ();
    void Off ();
	void SetColor (byte r, byte g, byte b) ;
};

/////////////////////////////////////////////
void brilla(byte pin, int velocita = 500) ;

#endif
