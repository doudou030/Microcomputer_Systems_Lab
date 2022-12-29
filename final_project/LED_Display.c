//LED_Display.c
#include "LED_Display.h"

void dispaly(unsigned input_k)
{ 
    //七段顯示器的Look up table
    char lut[17]={
    0b11000000, // 0 do
    0b11111001, // 1 #do
    0b10100100, // 2 re
    0b10110000, // 3 #re
    0b10011001, // 4 mi
    0b10010010, // 5 fa
    0b10000010, // 6 #fa
    0b11111000, // 7 sol
    0b10000000, // 8 #sol
    0b10010000, // 9 la
    0b10001000, // a #la
    0b10000011, // b si
    0b11000110, // c start record
    0b10100001, // d start play record
    0b10000110, // e Shift
    0b10001110, // f play default song
    0xff        // default
    };
    P0 = lut[input_k];
}
