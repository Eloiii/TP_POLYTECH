.global _start
_start:
    mov sp, #0xFF
    mov r0, #9
    mov r1, #4
    bl _div       // first call to _div(9,4)
    mov r0, #3
    mov r1, #4
    bl _div       // first call to _div(3,4)
    mov r0, #4    // n <- 4
    mov r1, #1    // f <- 1
    bl _fact

    mov r0, #0x48
    bl _writec
    mov r0, #0x45
    bl _writec
    mov r0, #0x4C
    bl _writec
    mov r0, #0x4C
    bl _writec
    mov r0, #0x4F
    bl _writec
    mov r0, #0x20
    bl _writec
    mov r0, #0x57
    bl _writec
    mov r0, #0x4F
    bl _writec
    mov r0, #0x52
    bl _writec
    mov r0, #0x4C
    bl _writec
    mov r0, #0x44
    bl _writec

    b _halt

_halt:
    b _halt
