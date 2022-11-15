//delay.c
#include"utils.h"

void delay(unsigned time) {
	for  (d1 = 0; d1 <1024; d1++) {
		for (d2 = 0; d2 < time; d2++){
		}
	}
}

void display(char flash) {
	// flash = 0 -> not flash
	// flash = 1 -> flash ten
	// flash = 2 -> flash digit
	if(flash == 0) {
		P1 = 0XD0 + ten;
		delay(5);
		P1 = 0XE0 + digit;
		delay(5);
	} else if (flash == 1) {
		
		if (flash_delay < 25) {
			P1 = 0XE0 + digit;
			delay(5);
			P1 = 0XDF ;
			delay(5);
			flash_delay = ((flash_delay + 1) % 50);
		} else {
			P1 = 0XE0 + digit;
			delay(5);
			P1 = 0XD0 + ten;
			delay(5);
			flash_delay = ((flash_delay + 1) % 50);
		}

	} else if (flash == 2) {
		if (flash_delay < 25) {
			P1 = 0XD0 + ten;
			delay(5);
			P1 = 0xEF;
			delay(5);
			flash_delay = ((flash_delay + 1) % 50);
		} else {
			P1 = 0XD0 + ten;
			delay(5);
			P1 = 0XE0 + digit;
			delay(5);
			flash_delay = ((flash_delay + 1) % 50);
		}
	}
}