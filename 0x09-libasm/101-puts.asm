BITS 64
CPU X64

	;; Prototype: size_t asm_puts(const char *str);
	global asm_puts
	extern asm_strlen

	segment .text

asm_puts:
	push rbp
	mov rbp, rsp
	call asm_strlen
	mov edx, eax
	mov esi, edi
	mov eax, 1
	mov edi, 1
	syscall
	mov rsp, rbp
	pop rbp
	ret
