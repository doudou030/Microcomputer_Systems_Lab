//Keypad4x4.c
#include "Keypad4x4.h"

unsigned char key;
char keypad4x4()
{
    for (char r = 0; r < 4; r++) {
        P1 = ~(1 << r);//往左位移r位
        key = P1 & 0b11111111;//檢查KEYPAD是否有按
        if (key != 0b11111111) {
            for (char c = 0; c < 4; c++) {
                if (!(key & (0b00010000 << c))) {
                    return c * 4 + r;
                }
            }
        }
    }
    return 16;
}
