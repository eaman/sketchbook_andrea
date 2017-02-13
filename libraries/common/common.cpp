/*  Common
 *
 *  Oggetti di uso comune
 *  Autore: Andrea Manni
 *
 *  Link: http://git.andreamanni.com/
 *  Licenza:    GPLv3
 */

#include "Arduino.h"
#include "common.h"

#define DEBUG_not

//////////////////////
// RGB LED
// Common anode / cat

RGBLed::RGBLed(byte pinR, byte pinG, byte pinB) {
    // Per un common catodo, valore max / min invertiti
    redPin    = pinR ;
    greenPin  = pinG ;
    bluePin   = pinB ;
    common    = 255 ;

    // Equvalente del Setup() per inizializzare i PIN
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
};

RGBLed::RGBLed(byte pinR, byte pinG, byte pinB, byte com) {
    // Per un common anode, valore max / min normali
    redPin    = pinR ;
    greenPin  = pinG ;
    bluePin   = pinB ;
    common    = com ;

    // Equvalente del Setup() per inizializzare i PIN
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
};

void RGBLed::SetColor (byte r, byte g, byte b) {
// Imposta il colore di un LED RGB
    analogWrite(redPin,   common - r);
    analogWrite(greenPin, common - g);
    analogWrite(bluePin,  common - b);

// Debug
#ifdef DEBUG
   Serial.print(common - r);
   Serial.print("-");
   Serial.print(common - g);
   Serial.print("-");
   Serial.print(common - b);
   while(1);
#endif

};

void RGBLed::Rand () {
// Imposta il colore di un LED RGB
    analogWrite(redPin, random(0,256));
    analogWrite(greenPin, random(0,256));
    analogWrite(bluePin, random(0,256));
};

void RGBLed::Red () {
// Accende il LED di rosso
    SetColor(255,0,0);
};

void RGBLed::Green () {
// Accende il LED di verde
    SetColor(0,255,0);
};

void RGBLed::Blue () {
// Accende il LED di blu
    SetColor(0,0,255);
};

void RGBLed::Magenta () {
// Accende il LED di magenta
    SetColor(255,0,255);
};

void RGBLed::Cyano () {
// Accende il LED di Cyano
    SetColor(0,255,255);
};

void RGBLed::Yellow () {
// Accende il LED di giallo
    SetColor(255,255,0);
};

void RGBLed::White () {
// Accende il LED
    SetColor(255,255,255);
};

void RGBLed::Off () {
// Spegne il LED
    SetColor(0,0,0);
};



/////////////////////////////////////
// Lampeggiatore
// Constructor
//
// Esempi incrementali: https://lab.piffa.net/sketchbook_andrea/multitasking/
Lampeggiatore::Lampeggiatore(int pin)
{
    ledPin = pin;
    pinMode(ledPin, OUTPUT);
    ledState = LOW;
    previousMillis = 0;
    interval = 500;
};

// Una funzione facente parte di una classe prende il nome di "metodo" della stessa:
void Lampeggiatore::Invert() {
    // Inverte il lampeggio
    ledState = HIGH ;
}

void Lampeggiatore::Blink() {
    // Illumina il led a 500ms

    if(millis() + shift - previousMillis > interval) {

        // if the LED is off turn it on and vice-versa:
        ledState = !ledState ; // Inverti il LED
        // set the LED with the ledState of the variable:
        digitalWrite(ledPin, ledState);
        // save the last time you blinked the LED
        previousMillis += interval;
    }
};

void Lampeggiatore::Blink(long time, long drift ) {
    // Illumina il led secondo un intervallo passato come argomento

    shift = drift;
    if(millis() + shift - previousMillis > time) {
        // if the LED is off turn it on and vice-versa:
        ledState = !ledState ; // Inverti il LED
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
        // save the last time you blinked the LED
        previousMillis += time;
    }
};

void Lampeggiatore::Blink(long up, long down, long drift ) {
    // Illumina il ledB precisando ontime e downtime

    shift = drift;
    if((ledState == HIGH)&& (millis() + shift - previousMillis > up)) {
        // save the last time you blinked the LED
        previousMillis += up;
        ledState = LOW  ;
    }
    else if((ledState == LOW)&& (millis() + shift - previousMillis > down)) {
        previousMillis += down;
        ledState = HIGH  ;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
};

void Lampeggiatore::High() {
    // Accende il LED
    digitalWrite(ledPin, HIGH);
}

void Lampeggiatore::Low() {
    // Spegne  il LED
    digitalWrite(ledPin, LOW);
}

void Lampeggiatore::Swap() {
    // Inverte lo stato del LED
    digitalWrite(ledPin, !digitalRead(ledPin));
}

/////////////////////////////////////
// Pwm
// Constructor
Pwm::Pwm(int pin)
// Gestione del PWM utilizzando millis
// per non bloccare il processore con delay
// Warning: serialWrite puo' interferire con i tempi.
{
    ledPin = pin;
    pinMode(ledPin, OUTPUT);
    previousMillis = 0;
    byte brightness = 0 ;
    increment = 1;
};

void Pwm::Up(long speed, long drift) {
    // Aumenta linearmente la luminosita' usanndo millis()
    // quindi senza bloccare il processore
    // Viene usato un float, in alternativa un coseno

    if (millis() != previousMillis)  { // si potrebbe togliere
        shift = drift;
        brightness = 255.0 /(float)speed * (millis() + shift);
        analogWrite(ledPin, brightness);

        previousMillis = millis();
    };
}

void Pwm::lUp(long speed, long drift) {
    // Aumenta usanndo millis() con correzione luminosita' LED
    // quindi senza bloccare il processore
    // Viene usato un float, in alternativa un coseno

    if (millis() != previousMillis)  { // si potrebbe togliere
        shift = drift;
        brightness = 255.0 /(float)speed * (millis() + shift);
        analogWrite(ledPin, lum(brightness));

        previousMillis = millis();
    };
}

void Pwm::Down(long speed, long drift) {
    // Riduce linearmente la luminosita' usanndo millis()
    // quindi senza bloccare il processore

    if (millis() != previousMillis)  {
        shift = drift;
        brightness = 255 - 255.0 /(float)speed * (millis() + shift) ;
        analogWrite(ledPin, brightness);

        previousMillis = millis();
    };
}

void Pwm::lDown(long speed, long drift) {
    // Riduce  usanndo millis() con correzione della luminosita'
    // quindi senza bloccare il processore

    if (millis() != previousMillis)  {
        shift = drift;
        brightness = 255 - 255.0 /(float)speed * (millis() + shift) ;
        analogWrite(ledPin, lum(brightness));

        previousMillis = millis();
    };
}

void Pwm::UD(long speed, long drift ) {
    // Aumenta e riduce in sequenza la luminosita' usanndo millis()
    shift = drift;
    brightness = 128 + 127 * cos(2 * PI / speed * (millis() + shift));
    analogWrite(ledPin, brightness);
}

void Pwm::Set(byte brightness) {
    // Imposta il valore del PWM
    analogWrite(ledPin, brightness);
}


void Pwm::lSet(byte brightness) {
    // Imposta il valore del PWM con correzione luminosita' LED
    analogWrite(ledPin, lum(brightness));
}


/////////////////////////////////////
// Sequenza
// Constructor
Sequenza::Sequenza (byte passed[], byte dim) {
    ledPins = passed ;
    size = dim ;
    for (int thisPin = 0; thisPin < size; thisPin++) {
        pinMode(ledPins[thisPin], OUTPUT);
    }
    previousMillis = millis();
    digitalWrite(ledPins[0], HIGH);
}

void Sequenza::Update(long value) {
    // Incrementa dal primo all'ultimo valore dell'array
    interval = value;
    if (millis() - previousMillis >= interval) {
        previousMillis = millis();

        if ( i < size - 1 ) {
            // Spegni precedente led
            digitalWrite(ledPins[i], LOW);

            // Accendi successivo led
            digitalWrite(ledPins[++i], HIGH);
        }

        else if  (i == size - 1 )   {
            // Ultimo caso
            i = 0;
            previousMillis = millis();
            digitalWrite(ledPins[i], HIGH);
            digitalWrite(ledPins[ size - 1 ], LOW);
        }
    }
}


void Sequenza::Reverse(long value) {
    interval = value;
    if (millis() - previousMillis >= interval) {
        previousMillis = millis();

        if  (i == 0)   { // Entry point, ultimo LED
            digitalWrite(ledPins[size -1],HIGH);
            digitalWrite(ledPins[0],LOW);
            i = size -1 ;
        }
        else {
            digitalWrite(ledPins[i],LOW);
            digitalWrite(ledPins[--i],HIGH);
        }
    }
}

void Sequenza::UD(long value) {
    interval = value;
    if (millis() - previousMillis >= interval) {
        previousMillis = millis();
        // Spegni precedente led
        digitalWrite(ledPins[i], LOW);
        i = i + inc ;
        // Accendi successivo led
        digitalWrite(ledPins[i], HIGH);

        if (i == 0 || i == size -1) {
            inc = -inc ;
        }
    }
}


//////////////////
// Funzioni


void brilla(byte pin, int velocita ) { // Defalt value di velocita' solo nell'Header
    // Accende e spegne il LED accetando un argomento
    // per impostare la velocita'.

    pinMode(pin, OUTPUT);
    // sequenze di istruzione: accendere e spegnere il LED
    digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(velocita);               // wait for a second
    digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
    delay(velocita);               // wait for a second
};


byte lum(byte val) {
    // Mappatura dell'intervallo 0-255 con correzione di luminosita.
    // storata in SRAM
    return pgm_read_byte_near(BCORRECT + val);
};


int calibraTrim(int pin, const byte ledPin) {
    /* START Calibrazione TRIM canale:
       Lettura di 10 smaple
       calcolo del valore medio esclusi gli 0

       I canali come alettoni / elevatore possono avere un TRIM
       (generalmente il throttle non ha un TRIM impostato),
       questa funzione nel setup serve per trovare il punto medio
       all'avvio dello sketch.
     */
    pinMode(ledPin,OUTPUT);
    byte a 		= 0;
    int servoValue 	= 0;
    int middle = 0; 
#ifdef DEBUG
    Serial.println(">> Calibrazione: ");
#endif 
    while (a < 10) {
        if (millis() > 10000) {
#ifdef DEBUG
            Serial.println(">> Calibrazione annullata a causa di assenza di seganle. \nAssicurarsi di accendere radio e ricevente \ne ripetere la procedura.");
#endif 
            middle = 15000; // Return value is divided by 10
            break;
        };
        servoValue = pulseIn(pin, HIGH, 25000);
        if (servoValue != 0 && servoValue > 950 && servoValue <2000)  {
            middle = middle + servoValue ;
            a++ ;
#ifdef DEBUG
            Serial.print(servoValue);
            Serial.print(": ");
            Serial.println(middle / a);
#endif 
            digitalWrite(ledPin, !digitalRead(ledPin));
            delay(50);
        }
    }
#ifdef DEBUG
    Serial.print(">> Fine Calibrazione, media: ");
    Serial.println(middle / 10 + 10);
    Serial.flush() ;
#endif 
    return(middle / 10 + 10) ;
// END calibrazione
};

