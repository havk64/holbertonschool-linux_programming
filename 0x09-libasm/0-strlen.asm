BITS 64

	;;
	;; asm_strlen - clone of strlen function. Finds the length of a string
	;;
	;; Prototype: size_t asm_strlen(const char *str);
	;; @str: a pointer to the string to be scanned
	;; Return: the number of bytes of the given string
	;;
	;; Uses registers to count (instead of variables on stack frame)
	;;

	global asm_strlen	; Export the symbol to be used by external files

segment .text			; Define the beginning of the .text (code) segment
asm_strlen:			; Define the asm_strlen routine
	push rbp		; Routine prologue
	mov rbp, rsp
	xor eax, eax		; Initialize the counter
	jmp start		; Skip the first increment

loop:				; Define the symbol to be used by the jnz instruction
	inc eax
start:	cmp BYTE [edi + eax], 0	; Compare each byte/char against zero
	jnz loop		; If not zero (NULL/End of string) keep counting

	mov rsp, rbp		; Routine epilogue
	pop rbp
	ret
