
# Choose your Qemu, set to your own path
QEMU=qemu-system-arm

# Choose your toolchain for ARM 
TOOLCHAIN=arm-none-eabi

# Choose your keyboard: azerty(fr) or qwerty(en-us)
# KEYBOARD=-k fr
KEYBOARD=-k en-us

####################################################################
# OPTIONS THAT YOU CAN CHANGE ARE ALL ABOVE THIS LINE.
# DO NOT CHANGE ANYTHING BELOW THIS LINE
# UNLESS YOU KNOW WHAT YOU ARE DOING
####################################################################

all: kernel.bin

clean: 
	rm -f *.o kernel.elf kernel.bin pingpong.s

kernel.bin: console.o io.o Makefile ldscript
	$(TOOLCHAIN)-ld -T ldscript $< io.o -o kernel.elf
	$(TOOLCHAIN)-objcopy -O binary kernel.elf kernel.bin

console.o: console.c Makefile
	$(TOOLCHAIN)-gcc -c\
		-mcpu=arm926ej-s\
		-Wall -g -O0 -o $@\
		$<

io.o: io.s Makefile
	$(TOOLCHAIN)-as -mcpu=arm926ej-s -gstabs+ $< -o $@

qemu: kernel.bin
	$(QEMU) -M versatilepb -nographic -m 64M -gdb tcp::1234 -S $(KEYBOARD) -kernel kernel.bin 

gdb: kernel.bin
	$(TOOLCHAIN)-gdb kernel.elf

pingpong.s: pingpong.c
	$(TOOLCHAIN)-gcc --specs=nosys.specs -Wall -S $<
