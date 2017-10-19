BITS 64
CPU X64
	;; Prototype: char *asm_strchr(const char *s, int c);
	global asm_strchr

	segment .text

asm_strchr:
	push rbp
	mov rbp, rsp
	push rcx
	mov eax, edi
loop:
	mov cl, BYTE [eax]
	cmp ecx, esi
	jz end
	test cl, cl
	jz eos
	inc eax
	jmp loop

end:
	pop rcx
	mov rsp, rbp
	pop rbp
	ret

eos:	mov eax, 0
	jmp end
