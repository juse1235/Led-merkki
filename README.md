# Salama
Sikin led salamaan ja Otit led merkkiin koodi, piirilevy ja ohjeet

## Piirilevyt
Piirretty Kicadilla.
Todo: Syövytystä varten maskit. Sik maski saattaa löytyä vielä jostain. Otitille ei ole tehty vaan levyt jyrsittiin.

### Piirilevyn kasausohje
TODO Pittää ettiä jostain...

## Ohjelma

Ohjelma siirtyy levylle kätevästi käyttäen arduinoa ohjelmointilaitteena.

```
Salaman ohjelmointiliittimen pinnit keskeltä reunalle:

Nro:  Nimi:   Arduinon pinni (nano):

6:    Reset   10
5:    GND     GND
4:    VCC     VCC
3:    SCK     13
2:    MISO    12
1:    MOSI    11

Muista vetää arduinon Reset ylös. Ardu nollautuu kun sarjaliikenne alotetaan....
```

Src hakemistossa on lediportit_oikein.h ja lediportit_väärin.h tiedostot joista jompikumpi kopioidaan lediportit.h tiedoston päälle mikäli ledit on juotettu vastoin ohjetta. (TODO: nimet ovat ehkä väärin)

Koodin kääntämiseen ja ohjelman levylle siirtämiseen komennot ovat:
```
// kääntäminen
avr-gcc -mmcu=attiny861 vilkutus.c salama.c -I./ -Os -DF_CPU=8000000UL  

// Fläsäys käyttäen arduino-isp:tä
avrdude -c avrisp -p t861 -B3 -P /dev/ttyUSB0 -b 19200 -U flash:w:a.out

// Fuse asetukset käyttäen arduino-isp:tä
avrdude -c avrisp -p t861 -B3 -P /dev/ttyUSB0 -b 19200 -U lfuse:w:0xe2:m -U hfuse:w:0xdf:m
```
