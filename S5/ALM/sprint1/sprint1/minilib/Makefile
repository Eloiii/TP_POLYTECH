
# Choose your Qemu, set to your own path
QEMU=qemu-system-arm

# Choose your toolchain for ARM 
TOOLCHAIN=arm-none-eabi

####################################################################
# OPTIONS THAT YOU CAN CHANGE ARE ALL ABOVE THIS LINE.
# DO NOT CHANGE ANYTHING BELOW THIS LINE
# UNLESS YOU KNOW WHAT YOU ARE DOING
####################################################################

all: io.o print.o

clean:
	rm -f *.o

io.o: io.s Makefile
	$(TOOLCHAIN)-as -mcpu=arm926ej-s -gstabs+ io.s -o io.o

print.o: print.s Makefile
	$(TOOLCHAIN)-as -mcpu=arm926ej-s -gstabs+ print.s -o print.o

