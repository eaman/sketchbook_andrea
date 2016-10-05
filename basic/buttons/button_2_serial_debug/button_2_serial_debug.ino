/*
  Input serial debug
 
 
 Accensione e spegnimanto di un LED utilizzando un pin come input.
 Utilizzare un bottone momentaneo per attivare il LED.

 Schemi del circuito per bottone in pull down:
 - http://lab.piffa.net/schemi/button_1_bb.png
 - http://lab.piffa.net/schemi/button_1_schem.png

Tutorial:
- 
 */

int led = 12;
int input = 2;

// the setup routine runs once when you press reset:
void setup() {                
  pinMode(led, OUTPUT);       // Il PIN e' attivato come output
  pinMode(input, INPUT);      // Il PIN e' attivato come output

  Serial.begin(9600);         // Attivazione seriale
}

// the loop routine runs over and over again forever:
void loop() {
  if (digitalRead(input) == HIGH) { // Verifica se il PIN input e' +5v
    digitalWrite(led, HIGH);
    Serial.println("Bottone premuto: circuito chiuso");  // Debug seriale
    delay(200);
  } 
  else { // Alterativa: se non e' +5v
    digitalWrite(led, LOW);
    Serial.println("Bottone libero: circuito aperto");  // Debug seriale
    delay(200);
  }
}

/* Domande:
 1. invertire il programma facendo in modo che il led si spenga
    quando il bottone e' premuto. Consoderare come ottenere lo stesso risultato
    modificando il circuito.
 2. Modificare il programma per far brillare il led cinque volte al secondo
    quando il bottone e' premuto.
 3. Si potrebbe usare un ciclo iterativo while invece che 
    un ciclo condizonale if? Che differenza c'e' tra il ciclo while e  for?
 4. Domanda: cosa succede se il jumper input non e' collegato ne al +5 ne al gound?
 */
