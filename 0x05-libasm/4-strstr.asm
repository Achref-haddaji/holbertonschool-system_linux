BITS 64

global asm_strstr				; export to the gcc link

asm_strstr:
	push rbp					; push the base
	mov rbp, rsp				; start new base

    mov R9, 0h
asm_loop:
    mov al, [rdi]
    mov bl, [rsi]

    cmp al, bl
    je check_correct

    cmp al, 0h
    je null_end

    inc rdi
    jmp asm_loop


check_correct:
    mov al,byte [rdi + R9]
    mov bl,byte [rsi + R9]

    inc R9

    cmp bl, 0h
    je found_end

    cmp al, 0h
    je null_end

    cmp al, bl
    je check_correct

    mov R9, 0h
    inc rdi
    jmp asm_loop

found_end:
	mov rax, rdi				    ; pass null
	mov rsp, rbp				; return to old base
	pop rbp						; pop to the call base
	ret

null_end:
	mov rax, 0h				    ; pass null
	mov rsp, rbp				; return to old base
	pop rbp						; pop to the call base
	ret
