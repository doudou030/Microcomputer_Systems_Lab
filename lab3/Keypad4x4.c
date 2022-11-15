//Keypad4x4.c
//Look up table
// char keypad[4][4] =   {{0 , 4 , 8 ,0xC},
//                        {1 , 5 , 9 ,0xD},
//                        {2 , 6 , 0xA ,0xE},
//                        {3 , 7 , 0xB ,0xF} };
#include "Keypad4x4.h"

unsigned char key;
char keypad4x4()
{
    for (char r = 0; r < 4; r++) {
        P1 = ~(1 << r);
        key = P1 & 0xF0;
        if (key != 0xF0) {
            for (char c = 0; c < 4; c++) {
                if (!(key & (0x10 << c))) {
                    return c * 4 + r;
                }
            }
        }
    }
    return -1;

}



















