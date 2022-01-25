mov r3, #0xFF
lsl r3, #8
add r3, r3, 0xDD
lsl r3, #8
add r3, r3, 0xEE
mov r1, #1000
strh r3, [r1]
