BITS 64
CPU X64
	;;
	;; asm_strstr - a clone of strstr function
	;;
	;; Description:	the strstr() function finds the first occurrence of the
	;; substring @sub in the string @s.
	;;
	;; @s: the pointer to the string
	;; @sub: a pointer to the substring to be searched for
	;; Return: a pointer to the beginning of the substring,
	;; or NULL if substring is not found.
	;;
	;; Prototype: char *asm_strstr(const char *s, char *sub);
	;;
	global asm_strstr

	segment .text

asm_strstr:
	push rbp		; Routine preamble
	mov rbp, rsp
	push rbx		; Save register's values/states
	push rcx
	push rdx
	mov cl, BYTE [esi]	; Read first byte of substring
	test cl, cl		; Test (bitwise AND) it
	jz null			; Case is NULL jump to 'null' subroutine

loop:
	movzx eax, BYTE [edi]	; Read one byte from @s
	cmp al, BYTE [esi]	; Compare with byte from @sub
	jz match		; If equal jump to 'match' subroutine
	inc edi			; Otherwise increase the pointer to @s
	test al, al		; Check for the end of string
	jnz loop		; While not NULL, loop
	xor eax, eax		; Otherwise return NULL

end:
	pop rdx			; Restore register's states/values
	pop rcx
	pop rbx
	mov rsp, rbp		; Routine prologue
	pop rbp
	ret			; Return

match:				; When the first character match...
	mov eax, edi		; Move the pointer of first matched char to eax
	xor ecx, ecx		; reset the counter
substr:
	inc ecx			; ...and increase the counter by one on each iteration
	mov bl, BYTE [edi + ecx] ; Read one byte from @s...
	mov dl, BYTE [esi + ecx] ; ...and one from @sub.
	test dl, dl		 ; Check for the end of @sub
	jz end			 ; If end of string, jump to end
	cmp bl, dl		 ; Otherwise compare both chars
	jz substr		 ; Loop while equal
	inc edi			 ; Otherwise increase the pointer
	jmp loop		 ; and jump back to outer loop

null:	mov eax, edi		; When @sub is NULL move pointer to eax
	jmp end			; and jump to end
