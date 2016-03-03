/* Blinker Demo */

// Includes
#include <avr/io.h>     // Mappatura dei PIN
#include <util/delay.h> // Funzione equivalente a delay()


int main(void) {

/* Blink AVR
 *
 * Blink senza utilizzare il framework di Arduino.
 *
 * Il pin 13 di Arduino corrisponde a PB5, il 6' PIN sulla porta PORTB
 * Invece il primo PIN sulla porta PORTB corrisponde a D8 di Arduino
 */

 // Setup
    DDRB |= 0b00100000;            /* Data Direction Register B:
                                   - il pin e' il 6' della porta:
                                   00100000 , 0b indica un numero binario
                                   - Utilizziamo una maschera binaria
                                   con l'operatore logico OR per cambiare
                                   solo il 6' BIT a 1 */


    // Ciclo infinito
    while (1) {

        PORTB = 0b00100000;     // Accendiamo il LED impostando tutti i PIN
        _delay_ms(1000);       // della porta                         

        PORTB = 0b00000000;     // Spegnamo il LED
        _delay_ms(1000);                             

    }                                // Fine del ciclo while (loop di arduino)
    return (0);  // Un programma in C deve sempre avere una valore di ritorno
                 // Per quanto questo non venga mai raggiunto dal uC 
}

