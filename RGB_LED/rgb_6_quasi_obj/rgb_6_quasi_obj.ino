/*
    RGB Object (quasi!)

    Gestione di un LED RGB tramite programmazione a oggetti
    Esercizio intermedio: manca constructor.

 Schema: http://lab.piffa.net/schemi/rgb.jpg
 */

class RGBLed {
  // Classe rappresentativa di un LED RGB
  
    byte redPin =11;
    byte greenPin =10;
    byte bluePin =9;
    byte redValue ;
    byte greenValue ;
    byte blueValue ;

  public:
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
} led; // Dichiariamo un instanza dell'oggetto


void setup()  {
      pinMode(9, OUTPUT);
      pinMode(10, OUTPUT);
      pinMode(11, OUTPUT);
}

void loop() {
  led.Arrossa();
  delay(1000);
  led.SetColor(255, 0, 255) ; // Mettiamo il LED in Green
  delay(1000);

}

/* Domande
 1. Potrei istanziare un altro oggetto RGBLed con PIN diversi?
 2. Posso accedere (leggere / modificare) le proprieta' dell'oggetto?
 3. A quali di queste proprieta' potrei voler accedere?
 4. Devo comunque abilitare i PIN come OUTPUT nel setup(): sarebbe possibile
    farlo tramite una funione, magari automaticamente?
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
 .
 1. Mi serve una funzione che permetta di assegnare delle proprieta come i PIN
 2. Al momento no: sono tutte PRIVATE. provate a spostarne alcune sotto
    la dichiarazione PUBLIC .
 3. Ad es. i colori che vado a modificare, i numeri dei pin su suppone 
    debbano restare immutati.
 4. Per usare una funzione nel setup() bisognerebbe rendere pubbliche 
    le proprieta' che indicano i PIM. 
	Meglio sarebbe avere una funzione che venga invocata una sola volta 
	al momento di instanziare l'oggetto. Un CONSTRUCTOR .
 */

