BITS 64
CPU X64

	;; Prototype: char *asm_strpbrk(const char *s, const char *accept);
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
