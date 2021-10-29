	.cpu arm7tdmi
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 1
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"main.c"
	.text
	.align	2
	.global	main
	.arch armv4t
	.syntax unified
	.arm
	.fpu softvfp
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, lr}
	sub	sp, sp, #8
	mov	r3, #3
	str	r3, [sp, #4]
	mov	r3, #2
	str	r3, [sp]
	mov	r3, #4
	mov	r2, #8
	mov	r1, r3
	mov	r0, #10
	bl	mul
	mov	r4, r0
	mov	r0, #9
	str	r0, [sp, #4]
	mov	r3, #65
	str	r3, [sp]
	mov	r3, #14
	mov	r2, #7
	mov	r1, #1
	bl	mul
	add	r0, r4, r0
	add	sp, sp, #8
	@ sp needed
	pop	{r4, lr}
	bx	lr
	.size	main, .-main
	.ident	"GCC: (15:9-2019-q4-0ubuntu1) 9.2.1 20191025 (release) [ARM/arm-9-branch revision 277599]"
