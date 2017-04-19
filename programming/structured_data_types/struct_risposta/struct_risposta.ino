/*
    struct 

 Struct e' un tipo struttura di dati non omogenea,
 puo' contenere tipi di dati diversi a differenza di un array.

 Possiamo quindi raggruppare diverse proprieta' di un oggetto
 sotto lo stesso identificatore.

 Schema: http://lab.piffa.net/schemi/rgb.jpg
 */


#include "lamp.h"

// instanziamo un lampeggino
lampeggino rosso { 13, 1000, 0, ">> Led Rosso <<"};

void setup()
{
    pinMode(rosso.pin, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    // Utilizziamo un lampeggiatore
   lampeggia(rosso);
}
