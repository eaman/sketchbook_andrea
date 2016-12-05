/*
  Analog PWM
  
  Impostare la frequenza del PWM tramite un input analogico.

- Schema: http://lab.piffa.net/schemi/arduino-pwm-diagram.png
  
  */
  
int inputPin = A0;  // set input pin for the potentiometer
int inputValue = 0; // potentiometer input variable
int ledPin = 3;     // output pin, deve avere il PWM

void setup() {
     // declare the ledPin as an OUTPUT:
     pinMode(ledPin, OUTPUT);
}

void loop() {
     // read the value from the potentiometer:
     inputValue = analogRead(inputPin);

     // send the square wave signal to the LED:
     analogWrite(ledPin, inputValue/4); 
     // la lettura analogica e' a 10 bit (0-1024)
     // Il PWM invece e' a 8 bit (0-255)
     // Circa 1024 / 4 ~= 255
     
     // Domanda: dovrebbe esserci un delay()?
}

