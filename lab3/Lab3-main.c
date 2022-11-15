//Lab3-main.c
#include <8051.h>
#include "LED_Display.h"
#include "Keypad4x4.h"

unsigned long sum=0;
char num, m; // m for mod

void main() {
	
	//sum = 0;
	
	P0 = 0xFF;//沒顯示
    m = 0;

	while (1) {
		num = keypad4x4();
		if (num != 255) {
			sum = ((((sum * 10) + num)) % 10000);
			delay(500);
			m++;
			if (m == 5)
				m = 4;
		}
		dispaly(sum, m);
	}
	
}


