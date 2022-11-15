all: Lab6-main.hex
Lab6-main.hex: Lab6-main.c
	sdcc Lab6-main.c
	packihx Lab6-main.ihx > Lab6-main.hex

# Lab6-main.ihx: Lab6-main.rel
# 	sdcc Lab6-main.rel

# Lab6-main.rel: Lab6-main.c
# 	sdcc -c Lab6-main.c

clean:
	del  *.rel *.asm *.lk *.lib *.map *.mem *.rst *.lst *.ihx *.rel *.sym *.hex

