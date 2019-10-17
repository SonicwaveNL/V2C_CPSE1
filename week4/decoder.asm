	.cpu cortex-m0
	.bss
		buffer: .space 40
	.text
	.align 2
	.global start

start:
	ldr r0, =compressed_song			// Load song into r0
	push { r4, r5, r6, r7, lr }			// Push r4, r5 and r6 to lr to stack
	mov	r5, r0							// Move content of r0 to r5
	ldr r0, =buffer						// Load buffer variable in r0
	mov r4, r0							// Copy r0 into r4
	bl decompress						// Branch link to decompress
	mov pc, lr							// End progress by moving lr back to pc

decompress:
	ldrb r0, [ r5 ]						// Load byte (char) from r5 in r0
	cmp	 r0, #0							// Add 0 to r0 to check if it's the end of the string
	beq	done							// When end of string go to done
	mov r2, #0							// Set duration counter to 0
	mov r3, #39							// Set index counter to 39
	cmp r0, #'@'						// Check if byte (char) in r0 is equal to '@'
	beq get_offsets						// If true go to get_offsets
	add	r5, r5, #1						// Go to next index in r5
	b	move_characters					// Branch to move_characters

get_offsets:
	add r5, r5, #1						// Go to next index of r5
	ldrb r1, [ r5 ]						// Load byte (char) from r5 in r1
	sub r1, #48							// Substract 48 ( ascii value '0' ) from r1 to get the decimal positions
	add r5, r5, #1						// Go to next index of r5
	ldrb r2, [ r5 ]						// Load byte (char) from r5 in r2
	sub r2, #48							// Substract 48 from r2 to convert a number char to corresponding decimal
	add r5, r5, #1						// Go to next index of r5
	b get_char							// Branch to get_char

get_char:
	ldrb r0, [ r4, r1 ]					// Load byte (char) from the buffer (r4) with offset r1 
	sub r2, r2, #1						// Substract 1 from the duration counter
	b move_characters					// Branch to move_characters

move_characters:
	sub r3, #1							// Substract 1 from the index counter to move 1 position to the left
	ldrb r6, [ r4, r3 ]					// Store byte (char) in r6, recieved from the buffer (r4) with offset r3
	add r3, #1							// Add 1 to the index counter to move 1 position to the right
	strb r6, [ r4, r3 ]					// Store byte (char) from r2 into r1 at current index
	sub r3, #1							// Substract 1 from the index counter to move 1 position to the left
	cmp r3, #0							// Check if index counter is at the end of the buffer
	beq store_char						// If yes go to store_char
	b move_characters					// Go to beginning of the move_characters loop

store_char:
	mov r3, #39							// Set the index counter back the beginning
	strb r0, [ r4, #0 ]					// Store r0 into r1 at index defined in r6 (begining of the buffer)
	push {r1, r2}						// Store r1 and r2 on the stack, to avoid problems with printing out the character
	bl show_result						// Print the byte (char) out
	pop {r1, r2}						// Get r1 and r2 from the stack
	cmp r2, #0							// Check if the position counter is at the end
	bgt get_char						// If the position counter isn't at the end, get another char
	b decompress						// Branch to start_moving

done:
	pop { r4, r5, r6, r7, pc }			// Pop r4, r5 and r6 from stack
	mov pc, lr