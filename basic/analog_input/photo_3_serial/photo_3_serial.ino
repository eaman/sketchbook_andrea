/*
  Photoresistor
 
 Utilizzare una fotoresistenza come analog input.
 Il comportamento della foto resistenza e' simile
 a un potenziometro: varia la resistenza in base alla 
 quantita' di luce.
 
 Per ottenere valori significativi utilizzare unaresistenza
 da ~5k ohms in serie con il sensore.
 
 Questo sketch modifica l'intervallo di intermittenza di un led
 in base alla luminosita' rilevata.
 
 Schema: http://lab.piffa.net/schemi/photoresistor_led.png
 Guida:  https://learn.adafruit.com/photocells/using-a-photocell
 */

int sensorPin = A0;   // select the input pin for the potentiometer
int ledPin = 3;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);  
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);    
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);  
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);          
  // turn the ledPin off:        
  digitalWrite(ledPin, LOW);   
  // stop the program for for <sensorValue> milliseconds:
  // print the results to the serial monitor:
  Serial.print("sensor = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t delay = ");      
  Serial.println(sensorValue);
  delay(sensorValue);                  
}

/* domande:
 1. qual'e' il valore minimo rilevato?
 2. quale il massimo?
 3. Modificare lo sketch in modo che modifichi la luminosita' di un LED 
via PWM tramite il valore letto dal sensore. (vedi esercizio sucessivo)
 */


