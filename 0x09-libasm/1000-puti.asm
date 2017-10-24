BITS 64
CPU X64

	;; Prototype: size_t asm_puti(int n);

	global asm_puti
	extern asm_putc

segment .text
asm_puti:
	push rbp
	mov rbp, rsp
	push r9
	xor r9d, r9d
	mov eax, edi
	test eax, eax
	js negative
	call print
	jmp end

negative:
	neg eax
	push rax
	mov edi, '-'
	call asm_putc
	add r9b, al
	pop rax
	mov edi, eax
	call print
end:
	pop r9
	mov rsp, rbp
	pop rbp
	ret

	;; Prototype int print(int n);
print:
	push rbp
	mov rbp, rsp
	push rbx
	push rcx
	mov ebx, 10
	xor ecx, ecx
iloop:	xor edx, edx
	div ebx
	sub rsp, 1
	mov [rsp], dl
	inc cx
	test eax, eax
	jnz iloop
pstr:	movzx edi, BYTE [rsp]
	or dil, 0x30
	call asm_putc
	add r9b, al
	add rsp, 1
	dec cx
	test cx, cx
	jnz pstr

end_print:
	mov eax, r9d
	pop rcx
	pop rbx
	mov rsp, rbp
	pop rbp
	ret

