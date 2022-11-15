//LED_Display.c
#include "LED_Display.h"
unsigned d1, d2;

void delay(unsigned n) {
	for  (d1 = 0; d1 < 1000; d1++){
		for  (d2 = 0; d2 < n; d2++);
	}
}

void dispaly(unsigned n, char mod)
{
    // mod for show how many digit
    for (char c = 0; c < mod; c++) {
        P0 = (~(0x10 << c) & 0xF0) + (n % 10);
        n /= 10;
        delay(0);
    }
}