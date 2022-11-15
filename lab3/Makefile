all: Lab3-main.hex

Keypad4x4.rel: Keypad4x4.c Keypad4x4.h
	sdcc -c Keypad4x4.c Keypad4x4.rel
LED_Display.rel: LED_Display.c LED_Display.h
	sdcc -c LED_Display.c LED_Display.rel
myIO.lib: LED_Display.rel Keypad4x4.rel
	sdar -rs myIO.lib LED_Display.rel Keypad4x4.rel

Lab3-main.hex: Lab3-main.c myIO.lib
	sdcc Lab3-main.c myIO.lib
	packihx Lab3-main.ihx > Lab3-main.hex


clean:
	del  *.rel *.asm *.lk *.lib *.map *.mem *.rst *.lst *.ihx *.rel *.sym *.hex

