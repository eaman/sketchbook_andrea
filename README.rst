Sketchbook di Andrea
=====================

Codice esempi per i corsi su Arduino.
Le ultime versioni sono disponibili su: git.andreamanni.com
- http://git.andreamanni.com/
- Interfaccia web: http://git.andreamanni.com/web

Gestione
--------------------

Per aggiornare il proprio archivio ::
    cd sketchbook_andrea/ ; git pull

Per instanziarne uno nuovo ::
    git clone --depth 1 git://git.andreamanni.com/sketchbook_andrea

Per cancellare completamente il vecchio e reinstanziarlo ::
    rm -r sketchbook_andrea ; git clone --depth 1 git://git.andreamanni.com/sketchbook_andrea

Se avete modificato degli sketch, non potete piu' scaricare gli aggiornamenti,
   siete disposti a perdere tutte le vostre modifiche:
   git stash ; git pull


Download via HTTP
--------------------

L'archivio e' comunque disponibile per un download via HTTP:
http://git.andreamanni.com/web?p=sketchbook_andrea;a=snapshot;h=HEAD;sf=tgz

::
    wget http://git.andreamanni.com/web?p=sketchbook_andrea;a=snapshot;h=HEAD;sf=tgz

Ordine sketches
================
Ordine da seguire per gli esercizi a seconda della traccia decisa per il corso.


Digital output
================================

Tutti i blinks in ordine, Dovrebbero coprire gli argomenti per :


- istruzioni
- sequenze di istruzioni (funzioni)
- cicli iterativi


Cicli condizionali vengono visti con bottoni mentre i cicli iterativi saranno
poi approfonditi con con i PWM.


Debug Seriale
================================

- basic/serial_debug/serial_hello_world/

Digital input
================================
Cicli condizionali

- basic/buttons/button_1
- basic/buttons/button_2_serial_debug/
(pull down e pull up)


Analog input
================================

- basic/analog_input/analogInput_1/analogInput_1.ino
- basic/analog_input/analogInput_2_serial/analogInput_2_serial.ino


Programmazione
================================
- Data types: http://www.ladyada.net/learn/arduino/lesson4.html
fare byte - int - long
- Magari uno script con serial print, eventualmente anche esadecimale


Analog Output
================================
Cicli iterativi while

- basic/pwm/pwm_0_manuale/pwm_0_manuale.ino Dimostrativo
- basic/pwm/pwm_1_while_byte/pwm_1_while_byte.ino
- basic/pwm/pwm_1_soluzione_doppio_while_byte/pwm_1_soluzione_doppio_while_byte.ino


Programmazione: operatori binari
================================

- programming/operators/operator_1_basic/operator_1_basic.ino
- programming/operators/operator_2_comparison/operator_2_comparison.ino


Analog Output
================================
Cicli iterativi For, operatore ternario

- Introduzione for loop: basic/pwm/pwm_2_for_loop/pwm_2_for_loop.ino
- basic/pwm/pwm_3_fade_reverser/pwm_3_fade_reverser.ino
- basic/pwm/pwm_4_analog_input/pwm_4_analog_input.ino



State machine
=================
Gestione stato di un bottone
Simple multitasking con millis() e due blink contemporanei

- basic/buttons/button_state_3/button_state_3.ino
- basic/buttons/button_state_4_state/button_state_4_state.ino

Programmazione: operatori logici
-----------------------------------

- programming/operators/operator_3_logic/operator_3_logic.ino

State machine: And
-------------------

- basic/buttons/button_state_4_state_and_condition/button_state_4_state_and_condition.ino



For loop
==========
Approfondimento su i cicli for, uso degli array

- programming/loops/loop_3_multi_led/loop_3_multi_led.ino
- Array: programming/loops/loop_4_multi_led_array/loop_4_multi_led_array.ino
- sketchbook_andrea/programming/loops/
- Random e interruzione del flusso del programma tramite if


Light sensor
===============

- basic/analog_input/photo_3_serial/
- Calibrazione manuale: basic/analog_input/photo_4_calibrated/
- Calibrazione automatica: basic/analog_input/photo_5_calibration/
- Smoothing: basic/analog_input/photo_6_smooth/
- basic/analog_input/photo_7_tonePitchFollower/

Piezo
========
- Traduzione tra due percezioni: basic/analog_input/photo_7_tonePitchFollower/
- Singole note e pull up: piezo/keyboard_three_pullup_buttons/
- Melodia: piezo/piezo_3_toneMelody/
- Melodia: piezo/piezo_4_mario_tune/



Status
==========

Completata la parte di:

- fondamenti di programmazione
- input / output digitali e analogici


State machine
=================
- Gestione stato di un bottone
- Simple multitasking con millis() e due blink contemporanei (questo si potrebbe
        fare anche dopo).


Sensori e attuatori
=======================
Fare un input e un output a rotazione

- piezo, suoni e knocking
- sensore luminosita'
- LED RGB (array)
- sensore temperatura
- pulsante capacitivo
- motori DC con transistor e diodo
- motori step


Devices
=============

Utilizzare specifici devices:

- sensore a ultrasuoni
- PIR 
- infrarossi / telecomando IR
- display LCD a due righe
- shift register
- POV persistence of vision
- display a matrice e a "8"
- connessione seriale via radio 
- programmare un Attiny85 con Arduino
- ethernet e WIFI

Makefile
============

Avendo installato il pacchetto ``arduino-mk``, con l'IDE /usr/local/software/arduino-1.6.5 , Arduino.mk resta quello originale della distribuzione posto in /usr/share/arduino/ .

/usr/share/arduino/Makefile ::

    # Arduino Make file. Refer to https://github.com/sudar/Arduino-Makefile

    BOARD_TAG       = uno
    MONITOR_PORT    = /dev/ttyACM0

    CURRENT_DIR     = $(shell pwd)
    OBJDIR          = /tmp/$(notdir $(shell pwd))
    ARDUINO_DIR     = /usr/local/software/arduino-1.6.5
    MONITOR_BAUDRATE = 115200

    include /usr/share/arduino/Arduino.mk
