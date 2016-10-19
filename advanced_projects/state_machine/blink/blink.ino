/*
   Blink con state machine

   Introduzione alle state machine

   */
int led = 13;
int pausa = 1000;
enum states_available { // Stati della FMS
    turn_on,    // Dinamico, transizione
    on,         // Statico
    turn_off,
    off
};

states_available state  ;

void setup() {
  pinMode(led, OUTPUT); 
  Serial.begin(9600);
  Serial.flush();
}

void loop() {
switch (state) {
    case turn_on :
    digitalWrite(led, HIGH);
    state = on ; // Setta il prossimo state
    break;

    case on:
    delay(pausa);
    state = turn_off ;
    break;

    case turn_off :
    digitalWrite(led, LOW);
    state = off ;
    break;

    case off :
    delay(pausa);
    state = turn_on ;
    break;

    default:    // In caso di default si fa turn_off
    digitalWrite(led, LOW);
    state = off ;
    break;

}
Serial.print(millis()); 
Serial.print(" \t Stato attuale ");
Serial.println(state);

}
