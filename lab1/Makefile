all: flash.hex

flash.hex: flash.ihx
	packihx flash.ihx > flash.hex
flash.ihx: flash.rel
	sdcc flash.rel
flash.rel: flash.c
	sdcc -c flash.c

clean:
	del  *.rel *.asm *.lk *.lib *.map *.mem *.rst *.lst *.ihx *.rel *.sym *.hex