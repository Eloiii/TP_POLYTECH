	.cpu arm7tdmi
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 1
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"print.c"
	.text
	.align	2
	.global	printf
	.type	printf, %function
printf:
	@ Function supports interworking.
	@ args = 4, pretend = 16, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 1
	@ link register save eliminated.
	stmfd	sp!, {r0, r1, r2, r3}
	mov	r0, #0
	add	sp, sp, #16
	bx	lr
	.size	printf, .-printf
	.ident	"GCC: (15:4.9.3+svn231177-1) 4.9.3 20150529 (prerelease)"
