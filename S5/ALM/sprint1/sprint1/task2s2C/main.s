	.cpu arm7tdmi
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
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
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #24
	mov	r3, #4
	str	r3, [fp, #-8]
	mov	r3, #0
	str	r3, [fp, #-12]
	ldr	r0, [fp, #-8]
	bl	square
	str	r0, [fp, #-12]
	ldr	r0, [fp, #-12]
	bl	square
	str	r0, [fp, #-12]
	mov	r3, #2
	str	r3, [fp, #-16]
	mov	r3, #3
	str	r3, [fp, #-20]
	mov	r3, #6
	str	r3, [fp, #-24]
	ldr	r2, [fp, #-24]
	ldr	r1, [fp, #-20]
	ldr	r0, [fp, #-16]
	bl	max
	str	r0, [fp, #-12]
	ldr	r1, [fp, #-20]
	ldr	r0, [fp, #-16]
	bl	puissance
	str	r0, [fp, #-12]
	ldr	r1, [fp, #-20]
	ldr	r0, [fp, #-16]
	bl	puissanceBis
	str	r0, [fp, #-12]
.L2:
	b	.L2
	.size	main, .-main
	.align	2
	.global	max
	.syntax unified
	.arm
	.fpu softvfp
	.type	max, %function
max:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #28
	str	r0, [fp, #-16]
	str	r1, [fp, #-20]
	str	r2, [fp, #-24]
	ldr	r2, [fp, #-16]
	ldr	r3, [fp, #-20]
	cmp	r2, r3
	ble	.L4
	ldr	r3, [fp, #-16]
	str	r3, [fp, #-8]
	b	.L5
.L4:
	ldr	r3, [fp, #-20]
	str	r3, [fp, #-8]
.L5:
	ldr	r2, [fp, #-24]
	ldr	r3, [fp, #-8]
	cmp	r2, r3
	ble	.L6
	ldr	r3, [fp, #-24]
	str	r3, [fp, #-8]
.L6:
	ldr	r3, [fp, #-8]
	mov	r0, r3
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	max, .-max
	.align	2
	.global	puissance
	.syntax unified
	.arm
	.fpu softvfp
	.type	puissance, %function
puissance:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	str	r0, [fp, #-16]
	str	r1, [fp, #-20]
	mov	r3, #1
	str	r3, [fp, #-8]
	mov	r3, #0
	str	r3, [fp, #-12]
	b	.L9
.L10:
	ldr	r3, [fp, #-8]
	ldr	r2, [fp, #-16]
	mul	r3, r2, r3
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L9:
	ldr	r2, [fp, #-12]
	ldr	r3, [fp, #-20]
	cmp	r2, r3
	blt	.L10
	ldr	r3, [fp, #-8]
	mov	r0, r3
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	puissance, .-puissance
	.align	2
	.global	puissanceBis
	.syntax unified
	.arm
	.fpu softvfp
	.type	puissanceBis, %function
puissanceBis:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	ldr	r3, [fp, #-12]
	cmp	r3, #0
	bne	.L13
	mov	r3, #1
	b	.L14
.L13:
	ldr	r3, [fp, #-12]
	sub	r3, r3, #1
	mov	r1, r3
	ldr	r0, [fp, #-8]
	bl	puissanceBis
	mov	r2, r0
	ldr	r3, [fp, #-8]
	mul	r3, r2, r3
.L14:
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
	.size	puissanceBis, .-puissanceBis
	.ident	"GCC: (15:9-2019-q4-0ubuntu1) 9.2.1 20191025 (release) [ARM/arm-9-branch revision 277599]"
