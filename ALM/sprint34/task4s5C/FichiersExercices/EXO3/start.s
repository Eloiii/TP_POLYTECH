.text
.align  2
.global main
main:
ldr r0,AdX
ldrb r0,[r0]
ldr r1, AdTabAscii
//....
AdX: .word X
AdTabAscii: .word TabAscii

.data
X:
.byte 35
TabAscii:
    .byte 0
    .byte 0


