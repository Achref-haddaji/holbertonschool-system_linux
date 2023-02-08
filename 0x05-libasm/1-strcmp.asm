BITS 64
global asm_strcmp
section .text

asm_strcmp:
	push rbp
	mov rbp, rsp

	mov al, [rdi]
	mov bl, [rsi]
	cmp al, bl
	jne end

	inc rdi
	inc rsi
	jmp loop

loop:
	mov al, [rdi]
	mov bl, [rsi]
	cmp al, bl
	jne end

	inc rdi
	inc rsi
	cmp al, 0
	je end
	jmp loop

end:
	sub al, bl
	mov rsp, rbp
	pop rbp
	ret
