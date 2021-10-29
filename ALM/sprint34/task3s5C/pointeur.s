	.cpu arm7tdmi
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 2
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"pointeur.c"
	.text
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC0:
	.ascii	"Valeur de a: %d\012\000"
	.align	2
.LC1:
	.ascii	"Valeur de b: %d\012\000"
	.align	2
.LC2:
	.ascii	"Valeur de l'adresse de a: %d\012\000"
	.align	2
.LC3:
	.ascii	"Valeur du pointeur sur a: %d\012\000"
	.align	2
.LC4:
	.ascii	"Valeur de l'adresse du pointeur p: %d\012\000"
	.align	2
.LC5:
	.ascii	"Nouvelle valeur de a: %d\012\000"
	.section	.text.startup,"ax",%progbits
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
	mov	r1, #10
	push	{r4, r5, r6, lr}
	ldr	r4, .L4
	ldr	r5, .L4+4
	ldr	r6, .L4+8
	ldr	r0, .L4+12
	str	r1, [r4]
	str	r1, [r6]
	str	r4, [r5]
	bl	printf
	ldr	r1, [r6]
	ldr	r0, .L4+16
	bl	printf
	mov	r1, r4
	ldr	r0, .L4+20
	bl	printf
	ldr	r1, [r5]
	ldr	r0, .L4+24
	bl	printf
	mov	r1, r5
	ldr	r0, .L4+28
	bl	printf
	mov	r2, #7
	ldr	r3, [r5]
	str	r2, [r3]
	ldr	r0, .L4+32
	ldr	r1, [r4]
	bl	printf
	mov	r0, #0
	pop	{r4, r5, r6, lr}
	bx	lr
.L5:
	.align	2
.L4:
	.word	a
	.word	pointeur
	.word	b
	.word	.LC0
	.word	.LC1
	.word	.LC2
	.word	.LC3
	.word	.LC4
	.word	.LC5
	.size	main, .-main
	.comm	pointeur,4,4
	.comm	b,4,4
	.comm	a,4,4
	.ident	"GCC: (15:9-2019-q4-0ubuntu1) 9.2.1 20191025 (release) [ARM/arm-9-branch revision 277599]"
