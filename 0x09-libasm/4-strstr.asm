BITS 64
CPU X64
	;; Prototype: char *asm_strstr(const char *s, char *sub);
	global asm_strstr

	segment .text

asm_strstr:
	push rbp
	mov rbp, rsp
	push rbx
	push rcx
	push rdx

loop:
	movzx eax, BYTE [edi]
	cmp al, BYTE [esi]
	jz match
	inc edi
	test al, al
	jnz loop

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
