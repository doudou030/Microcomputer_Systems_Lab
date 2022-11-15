all: Lab5-main.hex


Lab5-main.hex: Lab5-main.c
	sdcc Lab5-main.c
	packihx Lab5-main.ihx > Lab5-main.hex


clean:
	del  *.rel *.asm *.lk *.lib *.map *.mem *.rst *.lst *.ihx *.rel *.sym *.hex

