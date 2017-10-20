BITS 64

	;;
	;; strlen clone - find the length of a string
	;;
	;; Prototype: size_t asm_strlen(const char *str);
	;; @str: a pointer to the string to be scanned
	;; Return: the number of bytes of the given string
	;; Using registers to count (no variables on stack frame)
	;;

	global asm_strlen
	segment .text

asm_strlen:
	push rbp		; Routine prologue
	mov rbp, rsp
	xor eax, eax		; Initialize the counter
	jmp start		; Skip the first increment

loop:
	inc eax
start:	cmp BYTE [edi + eax], 0	; Compare each byte/char against zero
	jnz loop		; If not zero (NULL/End of string) keep counting

	mov rsp, rbp		; Routine epilogue
	pop rbp
	ret

