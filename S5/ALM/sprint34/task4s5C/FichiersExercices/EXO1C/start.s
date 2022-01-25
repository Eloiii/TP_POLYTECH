.global main
main:
    ldr r0, .string_ptr
    bl print_string       // affiche la chaine se trouvant à l'adresse contenu dans r0 a la console
    b main
.align 2
.global print_string
.type print_string,%function
.func print_string,print_string
print_string:
// corps de la fonction print_string...

.size print_string,.-print_string
.endfunc

.string_ptr:
    .word string
string:
    .ascii "CA MARCHE!\000"
