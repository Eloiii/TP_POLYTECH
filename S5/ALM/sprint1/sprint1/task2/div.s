mov r0, #0x48
    bl _writec

/*
* A function that computes a quotient, from a dividend in r0
* and a divisor in r1. The quotient is returned in r0 and the
* remainder in r2.
* Call this function using a branch-and-link.
* Clobbered: r0,r2,lr
*/
.global _div
        .type _div,%function
        .func _div,_div
_div:
        cmp r0, r1
        blt _ret
        sub r0, r0, r1
        add r2, r2, #1
        .size   _div, .-_div
        .endfunc
_ret:
        mov pc, lr
	