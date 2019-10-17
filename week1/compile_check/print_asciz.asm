	.cpu cortex-m0
	.text
	.align 2
	.global print_asciz

print_asciz:
	push	{ r5, lr }
	mov	r5, r0

loop_asciz:
	ldrb	r0, [ r5 ]
	add	r0, r0, #0
	beq	done_asciz
	bl	uart_put_char
	add	r5, r5, #1
	b	loop_asciz

done_asciz:
	pop { r5, pc}
