_start:
    ldr r0, .string_ptr
    bl print_string

print_string:
    cmp r0, #0
    beq halt
    add r0, r0, #4
    bl _writec
.string_ptr:
    .word string

halt:
    b halt
string:
    .ascii "CA MARCHE ! \000"