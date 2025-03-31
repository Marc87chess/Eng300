/*   .data
a: .byte 'o','r','a','n','g','e',0x00

    .global __do_copy_data
    .text
    .global main
    
    

f1:
    ld r18, X 
    ret
    
    
    
main:
    lds r18, a // initalize data memory
    ldi r26, 0x00// initilize X register pair
    ldi r27, 0x40
    ldi r20,0x01//for adding one
    ldi r19, 0x00// for comparing against
    ldi r21, 0x00// temp storage for len
check_string:   
    call f1
    add r26, r20
    add r21, r20
    cp r19,r18 // check if we hit the null terminiator
    brne check_string
    
    subi r21, 0x01 // len is one too long so this acounts for it
    mov r18, r21   // moves len into r18
    
    
    
    
    nop
*/
    