BITS 64
CPU X64

	;; Prototype: size_t asm_puti_base(int n, const char *base);

	global asm_puti_base
	extern asm_putc
	extern asm_strlen

segment .text
asm_puti_base:
	push rbp
	mov rbp, rsp
	push rdx
	push r8
	push r9
	push rdi
	mov rdi, rsi
	call asm_strlen
	mov edx, eax
	pop rdi
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
	pop r8
	pop rdx
	mov rsp, rbp
	pop rbp
	ret

	;; Prototype int print(int n, const char *base, size_t length);
print:
	push rbp
	mov rbp, rsp
	push rbx
	push rcx
	push rdx
	lea rbx, [rsp]
	xor ecx, ecx
iloop:	xor edx, edx
	div DWORD [rbx]
	sub rsp, 1
	mov [rsp], dl
	inc cx
	test eax, eax
	jnz iloop
pstr:	movzx r8d, BYTE [rsp]
	movzx edi, BYTE [rsi + r8]
	call asm_putc
	add r9b, al
	add rsp, 1
	dec cx
	test cx, cx
	jnz pstr

end_print:
	mov eax, r9d
	pop rdx
	pop rcx
	pop rbx
	mov rsp, rbp
	pop rbp
	ret

