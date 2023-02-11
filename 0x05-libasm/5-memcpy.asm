section .data

section .text
    global  asm_memcpy

asm_memcpy:
    ; Save the arguments on the stack
    push    rbp
    mov     rbp, rsp
    sub     rsp, 16
    mov     [rbp-8], rdi
    mov     [rbp-16], rsi
    mov     [rbp-24], rcx

    ; Load the source and destination addresses into rsi and rdi respectively
    mov     rsi, [rbp-16]
    mov     rdi, [rbp-8]

    ; Load the length into rcx
    mov     rcx, [rbp-24]

    ; Start copying the bytes
    cld
    rep movsb

    ; Restore the stack pointer and return
    mov     rsp, rbp
    pop     rbp
    ret
