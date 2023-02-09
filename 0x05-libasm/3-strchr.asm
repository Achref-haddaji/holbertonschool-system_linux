BITS 64

global asm_strchr

section .text
   asm_strchr:
         push rbp
         mov rbp, rsp
         xor rcx, rcx
   loop_in_str:
      mov al , [rdi + rcx]
      cmp al , sil
      je return_pointer
      inc rcx
      cmp al , 0
      je return_null
      jmp loop_in_str
   return_null:
      xor rax , rax
      jmp return

   return_pointer:
      add rdi, rcx
      mov rax , rdi
      jmp return
   return:
      mov rsp , rbp
      pop rbp
      ret
