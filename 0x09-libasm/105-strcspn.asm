BITS 64
CPU X64

	;;
	;; asm_strcspn - clone of strcsnp in x86 Assembly
	;;
	;; Description:	calculates the length of the initial segment of @s which
	;; consists entirely of bytes not in @reject.
	;;
	;; Prototype: size_t asm_strcspn(const char *s, const char *reject);
	;; @s: a pointer to a string
	;; @reject: a pointer to a substring
	;; Return: the number of bytes in the initial segment of @s which are
	;; not in the string @reject.
	;;

	global asm_strcspn

segment .text
asm_strcspn:
	push rbp
	mov rbp, rsp
	push rbx
	push rcx
	push rdx
	xor eax, eax
	xor ecx, ecx

loop:
	movzx ebx, BYTE [edi + ecx]
	test bl, bl
	jz end
	jmp inner
outter:	inc eax
	inc ecx
	jmp loop

end:
	pop rdx
	pop rcx
	pop rbx
	mov rsp, rbp
	pop rbp
	ret

inner:
	xor edx, edx
iloop:	movzx r8d, BYTE [esi + edx]
	test r8b, r8b
	jz outter
	inc edx
	cmp bl, r8b
	jz end
	jmp iloop
