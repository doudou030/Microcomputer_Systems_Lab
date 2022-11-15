//Lab4-main.c
#include <8051.h>
//65536-50000=15536
#define INIT_TIMER 15536
char timer = 0;
char counter = 0;
unsigned d1, d2;

void timer_isr (void) __interrupt (1) __using (1)
{
    counter++;
    // initial TH0,TL0 = 15536
    TH0 = (INIT_TIMER >> 8);
    TL0 = (INIT_TIMER & 0xff);
}

void delay(unsigned time) {
	for  (d1 = 0; d1 <1024; d1++) {
		for (d2 = 0; d2 < time; d2++){
		}
	}
}

void display()
{
    P1 = 0XD0 + (timer / 10);
    delay(5);
    P1 = 0xE0 + (timer % 10);
    delay(5);
}

void main() {
    //set M0 on
    TMOD = 0x01;
    // set TR0 on
    TCON = 0x10;
    // set EA, ET0 on
    IE = 0x82;
    // initial TH0,TL0 = 15536
    TH0 = (INIT_TIMER >> 8);
    TL0 = (INIT_TIMER & 0xff);
    while (1) {
        if (counter > 10) {
            counter = 0;
            timer = ((timer + 1) % 99);
        }
        display();
    }
}