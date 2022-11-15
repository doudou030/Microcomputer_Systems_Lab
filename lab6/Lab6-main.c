//Lab6-main.c 跑馬燈

#include <8051.h>
#define PIC_COUNT 3
unsigned d1, d2, d3, d4, d5;
unsigned char current_frame, current_pic;

unsigned frame[PIC_COUNT][8] = {
	// pic1
	{
		0b10011001,
		0b11011101,
		0b11001011,
		0b11100111,
		0b10001111,
		0b11001111,
		0b10011111,
		0b10011111,
	},
	// pic2
	{	
		0b11111101,
		0b00111001,
		0b11010111,
		0b01001111,
		0b10011011,
		0b10000111,
		0b00111111,
		0b00111111,
	},
	// pic3
	{
	
		0b11111011,
		0b11100011,
		0b11101011,
		0b11100111,
		0b11000111,
		0b11001111,
		0b10011111,
		0b10011111,
	}
};

void delay(unsigned time) {
	for  (d3 = 0; d3 < 50; d3++) {
		for (d4 = 0; d4 < time; d4++){
		}
	}
}

void display() {
	for (d1 = 0; d1 < 8; d1++) {
		P0 = (1 << d1) ^ 0xff; // 顯示哪個 row
		P2 = frame[current_pic][d1]; // 顯示哪個 column
		delay(5);
	}
}



void main()
{
	P1 = 0xff;
	P2 = 0xff;
	current_frame = 0;
	current_pic = 0;
	while (1) {
		// 每個圖跑 50 次
		current_frame = ((current_frame + 1) % (PIC_COUNT * 50));
		current_pic = (current_frame / 50);
		display();
	}
}