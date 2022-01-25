.global _fact
        .type _fact,%function
        .func _fact,_fact
_fact:
        cmp r0, #1
        moveq r0, r1
        beq _ret
        mul r1, r0, r1
        sub r0, r0, #1
        b _fact
        .size   _fact, .-_fact
        .endfunc
_ret:
        mov pc, lr
	