.text
.align  2
.global main
main:
ldr r0, .AdX
ldrb r0,[r0]
ldr r1, .AdtabAscii
//...
.data
.balign 4
.AdX:
    .word X
.X:
.byte 35

.balign 4
 .AdTabAscii: .word .TabAscii

.TabAscii:
    .byte 0
    .byte 0


