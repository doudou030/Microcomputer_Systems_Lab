all: Lab4-main.hex


Lab4-main.hex: Lab4-main.c
	sdcc Lab4-main.c
	packihx Lab4-main.ihx > Lab4-main.hex

clean:
	del  *.rel *.asm *.lk *.lib *.map *.mem *.rst *.lst *.ihx *.rel *.sym *.hex

