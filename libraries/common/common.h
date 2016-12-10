/*
  Common Class

  Oggetti comuni

*/

#include "Arduino.h"
#ifndef common_h
#define common_h


class RGBLed {
  // Classe rappresentativa di un LED RGB
  protected:    // Vedi esempio Ereditarieta'
    byte redPin ;
    byte greenPin ;
    byte bluePin ;
    byte redValue ;
    byte greenValue ;
    byte blueValue ;

  public:
    RGBLed (byte pinR, byte pinG, byte pinB) ;
	void SetColor (byte r, byte g, byte b) ;
	void Red ();
    void Green ();
    void Blue ();
    void Magenta ();
    void Cyano ();
    void White ();
    void Yellow ();
    void Off ();
};



class Lampeggiatore {
    // Lampeggia un LED utilizzando millis()
    // Variabili
    int ledPin ;           // il numero del LED pin
    long interval ;        // milliseconds di intervallo nel lampeggiare
    long previousMillis ;  // precedente cambio di stato
    int ledState ;         // stato attuale del LED, pubblico per invertirlo

    // Constructor: come viene instanziato un oggetto facente parte della classe
public:
    Lampeggiatore(int pin);
    void Invert();   // Inverte il lampeggio 
    void Blink(); 	// Lampeggia ogni 500ms
    void Blink(long interval); // Lampeggia inpostando l'intervallo
    void Blink(long on, long down); // Imposta il tempo acceso e il tempo spento
};



////////////////////////////
class Pwm {
    /*
       PWM per un LED: aumentare progressivamente la luminosita'.
       Utilizza la funzione millis() invece che un delay()
       in modo da non blocare il processore.
    */
    // Variabili
    int ledPin ;           // il numero del LED pin
    int speed ;            // velocita' del ciclo in ms
    long previousMillis ;  //precedente cambio di stato
    byte increment ;        // aumenta brighteness nel loop UD

    // Constructor: come viene instanziato un oggetto facente parte della classe
public:
    Pwm(int pin);  // numero di pin, velocita' di ciclo
    void Up(long speed);
    void Down(long speed);
    void UD(long speed);
    byte brightness  ;      // luminostia' iniziale
};

//////////////////////
// Funzioni

void brilla(byte pin, int velocita = 200) ;
#endif
