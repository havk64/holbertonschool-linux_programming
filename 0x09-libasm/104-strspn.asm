BITS 64
CPU X64

	;;
	;; asm_strspn - clone of strspn function in X86 Assembly
	;;
	;; Description:	calculates the length (in bytes) of the initial segment
	;; of @s which consists entirely of bytes in @accept.
	;;
	;; Prototype: size_t asm_strspn(const char *s, const char *accept);
	;; @s: a pointer to a string
	;; @accept: a pointer to a substring
	;; Return: the number of bytes in the initial segment of @s which consist
	;; only of bytes from @accept.
	;;

	global	asm_strspn

segment .text
asm_strspn:
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
	jz end
	inc edx
	cmp bl, r8b
	jnz iloop
	jmp outter
