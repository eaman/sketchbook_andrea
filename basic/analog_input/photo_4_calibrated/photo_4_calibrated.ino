/*
  Photoresistor
 
 Utilizzare una fotoresistenza come analog input.
 Il comportamento della foto resistenza e' simile
 a un potenziometro: varia la resistenza in base alla 
 quantita' di luce.
 
 Per ottenere valori significativi utilizzare unaresistenza
 da ~5k - 10k ohms in serie con il sensore.
 
 Questo sketch modifica l'intervallo di intermittenza di un led
 in base alla luminosita' rilevata.
 
 Schema: https://learn.adafruit.com/assets/460
 */

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 11;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

int min = 60;        // valore minimo rilevato dal sensore
int max = 600;        // valore massimo rilevato dal sensore

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);  
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);   
  delay(5); // stabilizziamo il sensore
  int calValue = map(sensorValue,min,max,0,255) ; 
  analogWrite(ledPin, calValue);  
  // Debug, per disabilitarlo togliere l'inizializzazione della seriale
  // dal setup()
  Serial.print("sensor = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t cal delay = ");      
  Serial.println(calValue);
}

/*
Domande:
1. Come fare per costringere la variabile dentro un intervallo stabilito?
2. Come si potrebbe eseguire la calibrazione automaticamente?
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

1. Utilizzando costrain()
2. Vedi esercizio sucessivo
*/

