
/*
 * A function that computes the sum of the elements of an array.
 * The array address is given in r0
 * The array length is given in r1
 * Returns the sum in r2.
 * Clobbered registers: r0,r1,r2,r3,r4
 */
	.align 2
.global _sum
	.type _sum,%function
	.func _sum,_sum
_sum:
	ldr r0,[pc]
	b   .L6
	.word array
.L6:	
	mov r2, #0  // the index
	mov r3, #0  // the sum
.L7:
	cmp r2, r1             // compare the index and length
	bge .L8                // done if index greater or equal
	ldr r4, [r0,r2,lsl#2]  // read next value (32bit word)
	add r3, r3, r4         // add the value to the sum
	add r2,r2,#1           // increment the index
	b .L7
.L8:
	mov r2,r3
	mov pc,lr
	.size	_sum, .-_sum
	.endfunc 