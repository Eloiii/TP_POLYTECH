
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

all: kernel.bin 

clean: 
	rm -f start.o kernel.elf kernel.bin io.o print_str.o print_str.s

kernel.bin: start.o print_str.o io.o ldscript
	$(TOOLCHAIN)-ld -T ldscript start.o io.o print_str.o -o kernel.elf
	$(TOOLCHAIN)-objcopy -O binary kernel.elf kernel.bin

start.o: start.s 
	$(TOOLCHAIN)-as -mcpu=arm926ej-s -gstabs+ start.s -o start.o

print_str.o: print_str.c 
	$(TOOLCHAIN)-gcc -c\
		-mcpu=arm926ej-s -gstabs+\
		-Wall -g -o $@\
		$<

print_str.s: print_str.c
	$(TOOLCHAIN)-gcc --specs=nosys.specs -Wall -O0 -S print_str.c 

io.o: io.s 
	$(TOOLCHAIN)-as -mcpu=arm926ej-s -gstabs+ io.s -o io.o

qemu: kernel.bin
	$(QEMU) -M versatilepb -nographic -m 64M -gdb tcp::1234 -S $(KEYBOARD) -kernel kernel.bin 

gdb: kernel.bin
	$(GDB) kernel.elf

