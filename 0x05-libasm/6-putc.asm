section .text

global asm_putc

asm_putc:
    ; push rbp onto the stack to preserve the value of the base pointer
    push rbp
    
    ; copy the value of the stack pointer into the base pointer
    mov rbp, rsp
    
    ; push rdi onto the stack to preserve its value
    push rdi
    
    ; set the system call number to 1 (sys_write)
    mov rax, 1
    
    ; set the first argument for sys_write (file descriptor for standard output) to 1
    mov rdi, 1
    
    ; set the second argument for sys_write (address of the buffer) to the stack pointer
    mov rsi, rsp
    
    ; set the third argument for sys_write (size of the buffer in bytes) to 1
    mov rdx, 1
    
    ; trigger the sys_write system call
    syscall
    
    ; restore the stack frame by copying the value of the base pointer into the stack pointer
    mov rsp, rbp
    
    ; restore the value of the base pointer from the stack
    pop rbp
    
    ; return control to the caller
    ret
