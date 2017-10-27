BITS 64
CPU X64

	;;
	;; asm_putc - prints one character to STOUT
	;;
	;; Description: This routine uses the 'write' syscall to print the @c
	;; integer as a character to the STDOUT.
	;; The corresponding C implementation is:
	;;
	;; size_t putc(int c)
	;; {
	;; 	return (write(1, &c, 1));
	;; }
	;;
	;; @c: the character to be printed
	;; Return: the value return by the 'write' syscall
	;;
	;; Prototype: size_t asm_putc(int c);
	;;
	global asm_putc

segment .text
asm_putc:
	push rbp		; Routine prologue, set new stack frame
	mov rbp, rsp
	push rcx		; Save registers state/values
	push rdx
	push rsi
	push rdi		; Copy the 1st arg to putc to the stack
	mov eax, 1		; eax carry the syscall number (1 for write)
	mov edx, 1		; 3rd arg is the amount of bytes to be written
	lea rsi, [rsp]		; 2nd arg is a pointer to the buffer to be printed
	mov edi, 1		; 1st arg is the number of file descriptor (1 for STDOUT)
	syscall			; Call to 'write'
	pop rdi			; Restore registers state/values
	pop rsi
	pop rdx
	pop rcx
	mov rsp, rbp		; Routine epilogue, take down stack frame
	pop rbp
	ret			; Return
