
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

all: kernel.bin binary_tree.s binary_tree_no-O1.s

clean: 
	rm -f start.o fact.o kernel.elf kernel.bin binary_tree.s binary_tree_no-O1.s

kernel.bin: start.o fact.o Makefile ldscript
	$(TOOLCHAIN)-ld -T ldscript start.o fact.o -o kernel.elf
	$(TOOLCHAIN)-objcopy -O binary kernel.elf kernel.bin

start.o: start.s Makefile 
	$(TOOLCHAIN)-as -mcpu=arm926ej-s -gstabs+ start.s -o start.o

fact.o: fact.s Makefile 
	$(TOOLCHAIN)-as -mcpu=arm926ej-s -gstabs+ fact.s -o fact.o

qemu: kernel.bin
	$(QEMU) -M versatilepb -nographic -m 64M -gdb tcp::1234 -S $(KEYBOARD) -kernel kernel.bin 

gdb: kernel.bin
	$(GDB) kernel.elf

binary_tree.s: binary_tree.c
	$(TOOLCHAIN)-gcc --specs=nosys.specs -Wall -S binary_tree.c -O1

binary_tree_no-O1.s: binary_tree.c
	$(TOOLCHAIN)-gcc -o $@ --specs=nosys.specs -Wall -S binary_tree.c
