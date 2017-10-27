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
	push rbp		; Routine prologue, set new stack frame
	mov rbp, rsp
	call asm_strlen		; Call asm_strlen to measure the string length
	mov edx, eax		; Use the length of the string as 3rd arg to write syscall
	mov esi, edi		; 2nd arg is the string
	mov edi, 1		; 1st arg is the file descriptor to write to (1 for STDOUT)
	mov eax, 1		; eax carry the syscall number (1 for write)
	syscall
	mov rsp, rbp		; Routine epilogue, take down stack frame
	pop rbp
	ret			; Return
