.global _start

.data
	var1: .word 0x1
	var2: .word 0x2
	var3: .word 0x5
.text
	ldr r0, =var1
	mov sp, #0xFF
	mov r1, #0
	mov r3, #0
	b .L1
.L1:
	ldr r2, [r0,r1]
	add r1, r1, #4
	add r3, r3, r2
	cmp r1, #12
	beq _halt
	b .L1
_halt:
	b _halt

.ltorg
