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
num2str:
	mov ebx, 10
	xor ecx, ecx
pushd:	xor edx, edx
	div ebx
	sub rsp, 1
	mov [rsp], dl
	inc cx
	test eax, eax
	jnz pushd
print:	movzx edi, BYTE [rsp]
	or dil, 0x30
	call asm_putc
	add r9b, al
	add rsp, 1
	dec cx
	test cx, cx
	jnz print
	mov eax, r9d
end:
	pop r9
	mov rsp, rbp
	pop rbp
	ret

negative:
	neg eax
	push rax
	mov edi, '-'
	call asm_putc
	add r9b, al
	pop rax
	mov edi, eax
	jmp num2str
