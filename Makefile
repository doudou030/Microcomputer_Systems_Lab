all:  eOrgan-108321042.hex

Keypad4x4.rel: Keypad4x4.c Keypad4x4.h
	sdcc -c Keypad4x4.c Keypad4x4.rel
LED_Display.rel: LED_Display.c LED_Display.h
	sdcc -c LED_Display.c LED_Display.rel

myIO.lib: LED_Display.rel Keypad4x4.rel
	sdar -rs myIO.lib LED_Display.rel Keypad4x4.rel 

 eOrgan-108321042.hex:  eOrgan-108321042.c myIO.lib
	sdcc  eOrgan-108321042.c myIO.lib
	packihx  eOrgan-108321042.ihx >  eOrgan-108321042.hex


clean:
	del  *.rel *.asm *.lk *.lib *.map *.mem *.rst *.lst *.ihx *.rel *.sym *.hex

