/*
  Common Class

  Oggetti comuni

*/

#include "Arduino.h"
#ifndef common_h
#define common_h


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

void brilla(byte pin, int velocita = 500) ;

#endif
