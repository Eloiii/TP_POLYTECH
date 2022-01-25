/**
 * PL011_T UART
 *     http://infocenter.arm.com/help/topic/com.arm.doc.ddi0183f/DDI0183.pdf
 * 
 * Data Register, at offset 0x00
 *    RX: read ascii codes, received from terminal
 *    TX: write ascii codes, to send to terminal
 *    Bit Fields:
 *      15:12 reserved
 *      11:08 error flags
 *       7:0  data bits
 * Flag Register, at offset 0x18
 *    Bit Fields:
 *      7:  TXFE  transmit FIFO empty
 *      6:  RXFF  receive FIFO full
 *      5:  TXFF  transmit FIFO full
 *      4:  RXFE  receive FIFO empty
 *      3:  BUSY  set when the UART is busy transmitting data
 */
.set UART0, 0x101f1000
.set UART1, 0x101f2000

.set UART_DR, 0x00
.set UART_FR, 0x18

.set UART_TXFE, (1<<7)
.set UART_RXFF, (1<<6)
.set UART_TXFF, (1<<5)
.set UART_RXFE, (1<<4)
.set UART_BUSY, (1<<3)


/*
 * Reads a character from the terminal through UART0
 * ATTENTION: waits until there is a character to read
 */
	.align 2
.global _readc
	.type _readc,%function
	.func _readc,_readc
_readc:
	push {r1,r2,lr}
	mov r2, #1
	lsl r2, #4          // RXFE = (1<<4)
	eor r0,r0,r0        // exclusive-or
	ldr r0,[pc]
	b .RXWAIT
	.word UART0
.RXWAIT:
	ldr r1, [r0,#0x18]  // flags at offset 0x18
	and r1, r1, r2      // flag set -> RX is empty, so wait
	cmp r1,#0
	bne .RXWAIT
	ldr r0, [r0,#0]     // RX at offset 0x00, half-word data
	pop {r1,r2,pc}
	.size	_readc, .-_readc
	.endfunc 

/*
 * Sends a character to the terminal through UART0
 * The character is given in r0.
 * IF the TX FIFO is full, this function awaits
 * until there is room to send the given character.
*/
	.align 2
.global _writec
	.type _writec,%function
	.func _writec,_writec
_writec:
	push {r0,r1,r2,r3,lr}
	mov r1, r0
	mov r3, #1
	lsl r3, #5 		// TXFF = (1<<5)

	ldr r0,[pc]
	b .TXWAIT
	.word UART0
.TXWAIT:
	ldr r2, [r0,#0x18]  	// flags at offset 0x18
	and r2, r2, r3 		// TX FIFO Full set, so wait
	cmp r2,#0
	bne .TXWAIT
	strb r1, [r0,#0x00]      // TX at offset 0x00
	pop {r0,r1,r2,r3,pc}
	.size	_writec, .-_writec
	.endfunc 

		


