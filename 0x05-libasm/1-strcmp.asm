BITS 64

global asm_strcmp

section .text
   asm_strcmp:
         push rbp
         mov rbp, rsp
         xor rcx, rcx
   loop_in_bytes_of_sour_and_dest:
            mov al, [rdi + rcx]
            mov bl, [rsi + rcx]
            cmp al, 0
            je compar
            cmp bl, 0
            je compar
            cmp al , bl
            jne compar
            inc rcx
            jmp loop_in_bytes_of_sour_and_dest
   compar:
      cmp al , bl
      je equal
      jg greater
      jl less
   equal:
      mov rax , 0
      jmp return
   greater:
      mov rax , 1
      jmp return
   less:
      mov rax , -1
      jmp return
   return:
      mov rsp , rbp
      pop rbp
      ret
