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
	push rbp
	mov rbp, rsp
	push rcx
	push rdx
	push rsi
	push rdi
	mov eax, 1
	mov edx, 1
	syscall
	pop rdi
	lea rsi, [rsp]
	mov edi, 1
	pop rsi
	pop rdx
	pop rcx
	mov rsp, rbp
	pop rbp
	ret
