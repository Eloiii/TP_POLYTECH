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
	.file	"mul.c"
	.text
	.align	2
	.global	mul
	.arch armv4t
	.syntax unified
	.arm
	.fpu softvfp
	.type	mul, %function
mul:
	@ Function supports interworking.
	@ args = 8, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	mul	r0, r1, r0
	mul	r0, r2, r0
	mul	r0, r3, r0
	ldr	r3, [sp]
	mul	r0, r3, r0
	ldr	r3, [sp, #4]
	mul	r0, r3, r0
	bx	lr
	.size	mul, .-mul
	.ident	"GCC: (15:9-2019-q4-0ubuntu1) 9.2.1 20191025 (release) [ARM/arm-9-branch revision 277599]"
