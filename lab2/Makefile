all: number.hex

utils.rel: utils.c utils.h
	sdcc -c utils.c utils.rel

myIO.lib: utils.rel
	sdar -rs myIO.lib utils.rel

number.hex: number.c myIO.lib
	sdcc number.c myIO.lib
	packihx number.ihx > number.hex

clean:
	del  *.rel *.asm *.lk *.lib *.map *.mem *.rst *.lst *.ihx *.rel *.sym *.hex 

