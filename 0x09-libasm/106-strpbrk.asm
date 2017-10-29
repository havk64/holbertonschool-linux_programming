BITS 64
CPU X64

	;;
	;; asm_strpbrk - clone of function strpbrk
	;;
	;; Description:	search a string for any of a set of bytes
	;;
	;; C Prototype: char *asm_strpbrk(const char *s, const char *accept);
	;; @s: a pointer to a string
	;; @accept: a pointer to a substring
	;; Return: a pointer to the byte in @s that matches one of the bytes
	;; in @accept, or NULL if no such byte is found.
	;;

	global asm_strpbrk

segment .text
asm_strpbrk:
	push rbp
	mov rbp, rsp
	push rbx
	push rcx
	lea eax, [edi]

loop:
	movzx ebx, BYTE [eax]
	test bl, bl
	jz notfound
	jmp inner
outter:	inc eax
	jmp loop

notfound:
	xor eax, eax
end:
	pop rcx
	pop rbx
	mov rsp, rbp
	pop rbp
	ret

inner:
	xor ecx, ecx
iloop:	movzx edx, BYTE [esi + ecx]
	test dl, dl
	jz outter
	inc ecx
	cmp bl, dl
	jz end
	jmp iloop
