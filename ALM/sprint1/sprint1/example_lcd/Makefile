
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
	rm -f *.o kernel.bin

kernel.bin: lcd_test.o Makefile ldscript
	$(TOOLCHAIN)-ld -T ldscript $< -o kernel.elf
	$(TOOLCHAIN)-objcopy -O binary kernel.elf kernel.bin

%.o: %.c Makefile
	$(TOOLCHAIN)-gcc -c\
		-mcpu=arm926ej-s\
		-Wall -g -O0 -o $@\
		$<

qemu: kernel.bin
	$(QEMU) -M versatilepb -m 64M -gdb tcp::1234 -S $(KEYBOARD) -kernel kernel.bin 

gdb: kernel.bin
	$(GDB) kernel.elf

