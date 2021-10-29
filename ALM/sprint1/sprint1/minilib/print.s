/* print_new_line - print a new line character */
    .global print_newline
    .type   print_newline, %function
print_newline:
    stmfd sp!, {r0, lr}

    mov r0, #10
    bl _writec

    ldmfd sp!, {r0, lr}
    mov pc, lr


/* print_int - print the content of r0 as a decimal integer */
    .global print_int
    .type   print_int, %function
print_int:
    stmfd sp!, {r0,r1,r2,r3,r4,lr}

    mov r3, #0
    /* We first stack all the digits in the string, ending by the value 0 */
.while:
    cmp r0, #10
    blt .end_while

    /* Divide by ten */
    mov r1, #10
    bl div

    /* Convert the rest of the division to ASCII */
    add r0, r0, #48 // 48 = '0'

    /* Push it in the string */
    ldr r4, .int_str
    add r4, r4, r3
    strb r0, [r4]
    add r3, r3, #1

    /* Put the rest of the integer in r0 and loop */
    mov r0, r2
    b .while

.end_while:
    // Last digit
    add r0, r0, #48 // 48 = '0'
    ldr r4, .int_str
    add r4, r4, r3
    strb r0, [r4]
    add r3, r3, #1

    /* Now we print all the digits in the right order */
.p_while:
    cmp r3, #0
    beq .end_p_while

    sub r3, r3, #1
    ldr r4, .int_str
    add r4, r4, r3
    ldrb r0, [r4]
    bl _writec

    b .p_while

.end_p_while:

    ldmfd sp!, {r0,r1,r2,r3,r4,lr}
    mov pc, lr

/* The string where digits are stored */
.int_str:
    .word .L1
.L1:
    .skip 12
/* ~print_string */


/* div - performs r0/r1, puts the results in r2 and the rest in r0 */
    .type   div, %function
div:
    mov r2, #0
.loop_div:
    cmp r0, r1
    blt .end_div

    sub r0, r0, r1
    add r2, r2, #1
    b .loop_div

.end_div:
    mov pc, lr
/* ~div */

_halt:
    b _halt

