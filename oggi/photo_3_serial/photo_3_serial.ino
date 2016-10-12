/*
  Photoresistor
 
 Utilizzare una fotoresistenza come analog input.
 Il comportamento della foto resistenza e' simile
 a un potenziometro: varia la resistenza in base alla 
 quantita' di luce.
 
 Per ottenere valori significativi utilizzare unaresistenza
 da ~5k ohms con il sensore.
 
 Questo sketch modifica l'intervallo di intermittenza di un led
 in base alla luminosita' rilevata.
 
 Schema: http://lab.piffa.net/schemi/photoresistor_led.png

Links:

- http://www.pighixxx.com/test/portfolio-items/connect-a-photoresistor/

Divisori di voltaggio:
- https://en.wikipedia.org/wiki/Electrical_resistivity_and_conductivity
- https://learn.sparkfun.com/tutorials/voltage-dividers
- http://www.pighixxx.com/test/wp-content/uploads/2014/10/126.png
 */

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
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
 3. Come adattare la risoluzione dell'attuatore alla sensibilita' del sensore?
 4. A cosa serve la resistenza da 10 - 5k ohms ?

 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
Risposte:

3. Vedi esercizio suciessivo
4. Serve come pull down per il pin che altrimenti sarebbe un sensore
ad alta impendenza flottante e come divisore di voltaggio.

 */


