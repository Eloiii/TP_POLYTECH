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
	.file	"var.c"
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
	@ link register save eliminated.
	ldr	r3, .L2
	mov	r2, #3
	str	r2, [r3]
	ldr	r3, .L2+4
	mov	r2, #1
	str	r2, [r3]
	ldr	r3, .L2+8
	mov	r2, #4
	str	r2, [r3]
	mov	r0, #0
	bx	lr
.L3:
	.align	2
.L2:
	.word	i
	.word	x
	.word	n
	.size	main, .-main
	.comm	x,4,4
	.comm	i,4,4
	.comm	n,4,4
	.ident	"GCC: (15:9-2019-q4-0ubuntu1) 9.2.1 20191025 (release) [ARM/arm-9-branch revision 277599]"
