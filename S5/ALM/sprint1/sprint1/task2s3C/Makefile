
# Choose your Qemu, set to your own path
QEMU=qemu-system-arm

# Choose your toolchain for ARM 
TOOLCHAIN=arm-none-eabi


# Looking for GDB...
GDB:=$(TOOLCHAIN)-gdb

ifeq (, $(shell which $(GDB)))
GDB:=gdb-multiarch
endif

ifeq (, $(shell which $(GDB)))
$(error "neither arm-none-eabi-gdb nor gdb-multiarch have been found")
endif


# Choose your keyboard: azerty(fr) or qwerty(en-us)
# KEYBOARD=-k fr
KEYBOARD=-k en-us

####################################################################
# OPTIONS THAT YOU CAN CHANGE ARE ALL ABOVE THIS LINE.
# DO NOT CHANGE ANYTHING BELOW THIS LINE
# UNLESS YOU KNOW WHAT YOU ARE DOING
####################################################################

all: kernel.bin main.s mul.s

clean: 
	rm -f *.o kernel.elf kernel.bin main.s mul.s

kernel.bin: main.o mul.o Makefile ldscript
	$(TOOLCHAIN)-ld -T ldscript main.o mul.o -o kernel.elf
	$(TOOLCHAIN)-objcopy -O binary kernel.elf kernel.bin

main.o: main.c Makefile
	$(TOOLCHAIN)-gcc -c\
		-mcpu=arm926ej-s -gstabs+\
		-Wall -g -o $@\
		$<

mul.o: mul.c Makefile
	$(TOOLCHAIN)-gcc -c\
		-mcpu=arm926ej-s -gstabs+\
		-Wall -g -o $@\
		$<

qemu: kernel.bin
	$(QEMU) -M versatilepb -nographic -m 64M -gdb tcp::1234 -S $(KEYBOARD) -kernel kernel.bin 

gdb: kernel.bin
	$(GDB) kernel.elf

main.s: main.c Makefile
	$(TOOLCHAIN)-gcc --specs=nosys.specs\
		-O1\
		-Wall -S main.c

mul.s: mul.c Makefile
	$(TOOLCHAIN)-gcc --specs=nosys.specs\
		-O1\
		-Wall -S $<
