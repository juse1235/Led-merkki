//"Mitä porttiin pitää työntää että saadaan tietty ledi palamaan"-taulukot
// JOS OOT JUOTTTANU KAIKEN VÄÄRINPÄIN NII TÄÄ SAATTAA EHKÄ TOIMIA!!12

#include <avr/io.h>

uint8_t alloff_pa = 0b11110000;
uint8_t alloff_pb = 0b00111100;


//                  76543210
uint8_t pa[32] = {0b11100001,  // 0
                  0b11010001,  // 2
                  0b10110001,  // 3
                  0b01110001,  // 4
                  0b11110001,  // 5
                  0b11110001,  // 6
                  0b11110001,  // 7
                  0b11110001,  // 8
                  0b11100010,  // 9
                  0b11010010,  // 01
                  0b10110010,  // 00
                  0b01110010,  // 02
                  0b11110010,  // 03
                  0b11110010,  // 04
                  0b11110010,  // 05
                  0b11110010,  // 06
                  0b11100100,  // 07
                  0b11010100,  // 08
                  0b10110100,  // 09
                  0b01110100,  // 21
                  0b11110100,  // 20
                  0b11110100,  // 22
                  0b11110100,  // 23
                  0b11110100,  // 24
                  0b11101000,  // 25
                  0b11011000,  // 26
                  0b10111000,  // 27
                  0b01111000,  // 28
                  0b11111000,  // 29
                  0b11111000,  // 31
                  0b11111000,  // 30
                  0b11111000}; // 32

uint8_t pb[32] = {0b00111100,   // 0
                  0b00111100,
                  0b00111100,
                  0b00111100,
                  0b00110100,   // 5
                  0b00101100,
                  0b00011100,
                  0b00111000,
                  0b00111100,
                  0b00111100,   // 01
                  0b00111100,
                  0b00111100,
                  0b00110100,
                  0b00101100,
                  0b00011100,   // 05
                  0b00111000,
                  0b00111100,
                  0b00111100,
                  0b00111100,
                  0b00111100,   // 21
                  0b00110100,
                  0b00101100,
                  0b00011100,
                  0b00111000,
                  0b00111100,   // 25
                  0b00111100,
                  0b00111100,
                  0b00111100,
                  0b00110100,
                  0b00101100,   // 31
                  0b00011100,
                  0b00111000}; // 32

