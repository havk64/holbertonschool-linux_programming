BITS 64
CPU X64

	;; Prototype: size_t asm_putc(int c);
	global asm_putc

	segment .text

asm_putc:
	push rbp
	mov rbp, rsp
	sub rsp, 4
	mov DWORD [rsp], edi
	mov eax, 1
	mov edi, 1
	mov rsi, rsp
	mov edx, 1
	syscall
	add rsp, 4
	mov rsp, rbp
	pop rbp
	ret
