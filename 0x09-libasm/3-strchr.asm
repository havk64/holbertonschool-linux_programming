BITS 64
CPU X64
	;;
	;; asm_strchr - clone of strchr (3) function
	;;
	;; Description:	The strchr() function returns a pointer to the first
	;; occurrence of the character @c in the string @s.
	;;
	;; @s: a pointer to the string to scanned
	;; @c: a character to be searched for
	;; Return: a pointer to the matched character or
	;; NULL if the character is not found.
	;; Prototype: char *asm_strchr(const char *s, int c);
	;;
	global asm_strchr

	segment .text

asm_strchr:
	push rbp		; Routine prologue
	mov rbp, rsp
	push rcx		; Save register to be used
	mov eax, edi		; Copy the first function argument to eax register
loop:
	movzx ecx, BYTE [eax]	; Read one byte of the string to low byte of ecx
	cmp ecx, esi		; Compare it agains the second argument
	jz end			; If they are equal jump to the end (returning eax)
	test cl, cl		; Test if the byte/char is NULL (end of string)
	jz eos			; If NULL jump to 'eos'
	inc eax			; Otherwise increment the pointer to the string
	jmp loop		; ...and loop again

end:
	pop rcx			; Routine epilogue
	mov rsp, rbp
	pop rbp
	ret

eos:	mov eax, 0		; If end of string return 0
	jmp end
