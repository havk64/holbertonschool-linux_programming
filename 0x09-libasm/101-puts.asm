BITS 64
CPU X64

	;;
	;; asm_puts - a assembly routine that prints a string to STDOUT
	;;
	;; @str: a pointer to the string to be printed.
	;; Return: the number of bytes printed.
	;;
	;; Prototype: size_t asm_puts(const char *str);
	;;
	global asm_puts
	extern asm_strlen

segment .text

asm_puts:
	push rbp
	mov rbp, rsp
	call asm_strlen
	mov edx, eax
	mov esi, edi
	mov edi, 1
	mov eax, 1
	syscall
	mov rsp, rbp
	pop rbp
	ret
