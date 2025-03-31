/*   .data
a: .byte 0x0a

    .global __do_copy_data
    .text
    .global main
        
main:
    lds r18, a
    mov r19, r18
    andi r19, 0b00001000// anding it with byte with 1 in the bit position we are intersted in
    lsr r19 // shift it 3 times to get it in the LSB
    lsr r19
    lsr r19
    mov r20, r18
    andi r20, 0b000000100
    lsr r20//shift it 2 times to get it in the LSB
    lsr r20
    mov r21, r18
    andi r21, 0b00000010
    lsr r21//shift it 1 time to get it in the LSB
   
    
    
    nop*/
    
  