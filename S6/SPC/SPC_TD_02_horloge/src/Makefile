CC = clang -O0
CCASM = $(CC) -S --target=armv5te-pc-linux-eabi

SRC = instrumentation.c fib.c memo_fib.c timer.c timer_sec.c hms.c chrono_fib.c int_of_string.c main.c

default:
	@less Makefile
	@clear
	@echo "USAGE"
	@echo "make run"
	@echo "./run <int:0..40>"


run:
	$(CC) -o run $(SRC)

asm: traitant.arm

%.arm: %.c
	$(CCASM) $< -o $@

.PHONY: run asm
