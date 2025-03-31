/*    .data
a: .byte 2
b: .byte 2
c: .byte 3
    .global __do_copy_data
    .text
    .global main
    
    
f2:
    ldi r18, 0x02
    add r24, r18
    ret

    
f1:
    // r24 has to contain the b argument of f1 to pass into f2 but we cannot loose r24 so
    push r24
    mov r24, r22
    
    call f2
    mov r18, r24 // stores return from f2 into r18 
    pop r24 // takes r24 off the top of the stack
    add r24, r18 // Z = V + F2(r)
    ret
    
    
    
    
    
    
main:
    lds r25, 0x00 // top byte is zero
    lds r24, a // argument a of f1
    lds r23, 0x00
    lds r22, b
    
    call f1
    
    sts c, r24
    nop
*/   
    