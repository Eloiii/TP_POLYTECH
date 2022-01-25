.global _start
_start:
	mov sp, #0xFF
.L6:
	mov r0, #3
	bl _fact
	mov r0,#0
_halt:
	b _halt
	
	
