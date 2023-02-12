BITS 64
global asm_puts
extern asm_strlen
section .text
   asm_puts:
         push rbp
         mov rbp, rsp

         ; Save the address of the string in rdi
         push rdi
         call asm_strlen
         pop rdi

         ; Save the length of the string in rdx
         mov rdx, rax

         ; Prepare the arguments for the write syscall
         mov rax , 1        ; write to stdout
         mov rsi, rdi       ; buffer address
         mov rdi , 1        ; file descriptor

         ; Invoke the write syscall
         syscall

         mov rsp , rbp
         pop rbp

         ret

