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

loop:
	movzx eax, BYTE [edi]
	cmp al, BYTE [esi]
	jz match
	inc edi
	test al, al
	jnz loop

end:
	pop rcx
	pop rbx
	mov rsp, rbp
	pop rbp
	ret

match:
	mov eax, edi
	mov ecx, 0
substr:
	inc ecx
	mov bl, BYTE [edi + ecx]
	test bl, bl
	jz end
	cmp bl, BYTE [esi + ecx]
	jz substr
	inc edi
	jmp loop
