.cpu cortex-m0
.text
hello: .asciz "HELLO world"
.align 2
.global application

application:
    ldr r0, =hello
    bl print_asciz
    mov pc,lr

print_asciz:
    push { r5, lr }
    mov r5, r0
    b loop

loop:
    ldrb r0, [ r5 ]
    cmp r0, #0
    beq done
    bl change_word                  // <<???
    bl uart_put_char
    add r5, r5, #1
    b loop

done:
    mov r0, r5
    pop { r5, pc }

change_word:
    push { r5, lr }
    cmp r0, #97
    bge to_upper
    cmp r0, #65
    bge to_lower
    b doneChange
    
to_upper:
    cmp r0, #122
    bgt doneChange
    sub r0, r0, #32
    b doneChange

to_lower:
    cmp r0, #90
    bgt doneChange
    add r0, r0, #32
    b doneChange

doneChange:
    pop { r5, pc }
