/*   .data
a: .byte 'h','i',0x00 // subtract 32 fromlower case acii to get uppercase

    .global __do_copy_data
    .text
    .global main
        
main:
    lds r18, a
    mov r19, r18
    subi r19, 0x20
    sts 0x4003, r19
    lds r19, 0x4001
    subi r19, 0x20
    sts 0x4004, r19
    lds 19 , 0x4002// copy NULL 
    sts 0x4005, r19
    
    
    nop
    
*/   