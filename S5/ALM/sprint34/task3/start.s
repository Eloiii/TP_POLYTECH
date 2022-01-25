.global _start
_start:
	mov sp, #0xFF
	ldr r0,[pc]    // load the array address in r0
	b   .L6
	.word array
.L6:
	mov r1,#4      // load the array length in r1
	bl _sum        // make the call to the function _sum
_halt:
	b _halt
	
array:
	.word 0x00
	.word 0x01
	.word 0x02
	.word 0x03