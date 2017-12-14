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
	push rbp
	mov rbp, rsp
	push rbx
	push rcx
	push rdx
	mov cl, BYTE [esi]
	test cl, cl
	jz null

loop:
	movzx eax, BYTE [edi]
	cmp al, BYTE [esi]
	jz match
	inc edi
	test al, al
	jnz loop
	xor eax, eax

end:
	pop rdx
	pop rcx
	pop rbx
	mov rsp, rbp
	pop rbp
	ret

match:
	mov eax, edi
	xor ecx, ecx
substr:
	inc ecx
	mov bl, BYTE [edi + ecx]
	mov dl, BYTE [esi + ecx]
	test dl, dl
	jz end
	cmp bl, dl
	jz substr
	inc edi
	jmp loop

null:	mov eax, edi
	jmp end
