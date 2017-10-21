BITS 64
CPU X64

	;; Prototype: size_t asm_strcspn(const char *s, const char *reject);
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
