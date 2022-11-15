//delay.h
#include <8051.h>
char ten, digit,sum;
int flash_delay;
unsigned d1, d2;

void delay(unsigned time);
void display(char flash);