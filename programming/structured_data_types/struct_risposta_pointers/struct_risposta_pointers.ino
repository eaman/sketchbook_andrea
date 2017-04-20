/*
    struct 

 Struct e' un tipo struttura di dati non omogenea,
 puo' contenere tipi di dati diversi a differenza di un array.

 Possiamo quindi raggruppare diverse proprieta' di un oggetto
 sotto lo stesso identificatore.

Questa versione permette alla funzione lempeggia() di modificare una delle proprieta
(  lo stato) dello struct rosso. Il fatto e' che una funzione non potrebbe modificare
dei dati al suo esterno! Al massimo potrebbe ritornare un valore...

Per superare questo si invoca la funziona con un riferimento ( & ) al dato originale
e poi nel corpo della funzione si usano pointers (foo->bar eqivale a (*foo).bar, 
l'operatore punto ha precedenza rispetto al pointer) per modificare un indirizzo di memoria
esterno alla funzione.

 Schema: http://lab.piffa.net/schemi/rgb.jpg
 */


#include "lamp.h"

// instanziamo un lampeggino
lampeggino rosso { 13, 1000, ">> Led Rosso <<"};

void setup()
{
    pinMode(rosso.pin, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    // Utilizziamo un lampeggiatore
   lampeggia(&rosso);
}
