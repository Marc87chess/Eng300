// data segment
/*    .data 
    .global __do_copy_data
var1: .byte 0x02, 0x33 // initalized 0x4000 and 0x4001
    .text
    .global main
main:
    ldi r16, 0x00 // a =4
    ldi r17, 0x04
    ldi r18, 0x01
    //ldi r19, 0x0a
cond_test:
    cp r16, r17
    brlt if_true
    jmp end_if
    
if_true:
    add r16, r18
    jmp cond_test
end_if:
    ldi r16, 0x00*/