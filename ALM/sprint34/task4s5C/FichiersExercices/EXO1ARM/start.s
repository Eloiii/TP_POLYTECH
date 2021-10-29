.global main
main:
    mov sp, #0xFF
    ldr r1, .string_ptr
    bl print_string       // affiche la chaine se trouvant à l'adresse contenu dans r0 a la console
    b main
.align 2
.global print_string
.type print_string,%function
.func print_string,print_string

print_string:
    mov r0, r1
    cmp r0, #'\'
    beq halt
    bl _writec
    add r0, r0, #4
    b print_string

.size print_string,.-print_string
.endfunc

halt:
    b halt

.string_ptr:
    .word string
string:
    .ascii "CA MARCHE!\000"
