#include <8051.h>

void main()
{
	unsigned d1, d2, tmp, led;
	P0 = P1 = P2  = 0xff; // turn off all led 

	while (1) {
		// clockwise
		// From P0 -> P2 -> P1 -> P0
		led = 0xdf;
		for (tmp = 0; tmp <= 6; tmp++) {
			P0 = led;
			led = (led >> 1) + 0x80; 				// right shift and plus the most significant bit (which is 1000 0000)
			for (d1 = 0; d1 < 1024; d1 ++) {
				for (d2 = 0; d2 < 100; d2 ++) {
				}
			}
		}
		led = 0x7f;
		for (tmp = 0; tmp <= 8; tmp++) {
			P2 = led;
			led = (led >> 1) + 0x80; 				// right shift and plus the most significant bit (which is 1000 0000)
			for (d1 = 0; d1 < 1024; d1 ++) {
				for (d2 = 0; d2 < 100; d2 ++) {
				}
			}
		}
		led = 0x7f;
		for (tmp = 0; tmp <= 8; tmp++) {
			P1 = led;
			led = (led >> 1) + 0x80; 				// right shift and plus the most significant bit (which is 1000 0000)
			for (d1 = 0; d1 < 1024; d1 ++) {
				for (d2 = 0; d2 < 100; d2 ++) {
				}
			}
		}
		led = 0x7f;
		for (tmp = 0; tmp <= 1; tmp++) {
			P0 = led;
			led = (led >> 1) + 0x80; 				// right shift and plus the most significant bit (which is 1000 0000)
			for (d1 = 0; d1 < 1024; d1 ++) {
				for (d2 = 0; d2 < 100; d2 ++) {
				}
			}
		}
		
		// counterclockwise
		// From P0 -> P1 -> P2 -> P0
		led = 0xbf;
		for (tmp = 0; tmp <= 2; tmp++) {
			P0 = led;
			led = (led << 1) + 0x01; 				// left shift and plus the most significant bit (which is 0000 0001)
			for (d1 = 0; d1 < 1024; d1 ++) {
				for (d2 = 0; d2 < 100; d2 ++) {
				}
			}
		}
		led = 0xfe;
		for (tmp = 0; tmp <= 8; tmp++) {
			P1 = led;
			led = (led << 1) + 0x01; 				// left shift and plus the most significant bit (which is 0000 0001)
			for (d1 = 0; d1 < 1024; d1 ++) {
				for (d2 = 0; d2 < 100; d2 ++) {
				}
			}
		}
		led = 0xfe;
		for (tmp = 0; tmp <= 8; tmp++) {
			P2 = led;
			led = (led << 1) + 0x01; 				// left shift and plus the most significant bit (which is 0000 0001)
			for (d1 = 0; d1 < 1024; d1 ++) {
				for (d2 = 0; d2 < 100; d2 ++) {
				}
			}
		}
		led = 0xfe;
		for (tmp = 0; tmp <= 6; tmp++) {
			P0 = led;
			led = (led << 1) + 0x01; 				// left shift and plus the last significant bit (which is 0000 0001)
			for (d1 = 0; d1 < 1024; d1 ++) {
				for (d2 = 0; d2 < 100; d2 ++) {
				}
			}
		}
	}
}
