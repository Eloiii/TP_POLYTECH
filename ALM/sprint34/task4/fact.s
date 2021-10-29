/*
 * Factorial function: the argument n in r0
 * Returns the computed result in r0
 * Clobbers r0 and r1.
 */
.align 2
.global _fact
	.type _fact,%function
	.func _fact,_fact
_fact:
	cmp r0, #1       // fact(1)=1
	bne .L0          // so if r0==1
	mov pc, lr       // return 1
.L0:
	push {r1,lr}        // save r1 in memory on the stack
	mov r1, r0	 // save r0 in r1
	sub r0,r0,#1     // compute (n-1)!
        bl _fact         // by recursively calling  _fact
	mul r0, r1, r0   // compute n*(n-1)!
        pop {r1}	 //restore r1
	ldr pc, [sp], #4
	.size	_fact, .-_fact
	.endfunc 