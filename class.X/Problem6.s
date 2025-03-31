    .data
var1: .byte 0x00
    .global __do_copy_data
    .text
    .global main
    
square:
    add r25, r23
    add r24, r22
    Mul r24, r22
    mov r24, r0
    ret
    
    
    
calc:
    add r25, r23// add high bytes
    add r21, r19
    add r25, r21//combine high bytes
    add r24, r22
    add r20, r18
    add r24, r20// combine low bytes
    mov r23, r19 // move y into pair two agrument value
    mov r22, r18
    call square
    ret
    
    
    

main:
    ldi r25, 0x00
    ldi r24, 0x01
    ldi r23, 0x00
    ldi r22, 0x01
    ldi r21, 0x00
    ldi r20, 0x02
    ldi r19, 0x00
    ldi r18, 0x02
    call calc
    sts 0x4000, r24
    
    