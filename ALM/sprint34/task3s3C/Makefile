
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

all: kernel.bin var.s 

clean: 
	rm -f var.o kernel.elf kernel.bin var.s

kernel.bin: var.o
	$(TOOLCHAIN)-ld  -T ldscript var.o -o kernel.elf 
	$(TOOLCHAIN)-objcopy -O binary kernel.elf kernel.bin


var.o: var.s 
	$(TOOLCHAIN)-as -mcpu=arm926ej-s -gstabs+ var.s -o var.o

qemu: kernel.bin
	$(QEMU) -M versatilepb -nographic -m 64M -gdb tcp::1234 -S $(KEYBOARD) -kernel kernel.bin 

gdb: kernel.bin
	$(GDB) kernel.elf

var.s: var.c
	$(TOOLCHAIN)-gcc --specs=nosys.specs -Wall -S var.c -O1



