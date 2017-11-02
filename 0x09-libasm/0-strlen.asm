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

section .text			; Define the beginning of the .text (code) section
asm_strlen:			; Define the asm_strlen routine
	push rbp		; Routine prologue
	mov rbp, rsp
	pxor xmm0, xmm0		; reset xmm0 (NULL comparison)
	mov eax, -16		; Initialize %eax to -16 to avoid one jmp

loop:
	add eax, 16		; Increment the counter by 16 each iteration
	pcmpistri xmm0, [edi + eax], 1000b ; Look for the end of string
	jnz short loop			   ; and generates an index on %ecx

	add eax, ecx		; Add the index to the counter to be returned
	mov rsp, rbp		; Routine epilogue
	pop rbp
	ret
