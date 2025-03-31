/*  .data
array: .byte 1, 2, 3, 4, 5

    .global __do_copy_data
    .text
    .global main
        
main:
    lds r18, array
    sts 0x4004, r18
    lds r18, 0x4002
    sts 0x4001, r18
  
    
    
    nop*/
    
 