BITS 64
CPU X64
	;; Prototype: void *asm_memcpy(void *dest, const void *src, size_t n);
	global asm_memcpy

	segment .text

asm_memcpy:
	push rbp
	mov rbp, rsp
	push rbx
	push rcx
	mov rcx, 0
	mov eax, edi

loop:
	cmp edx, ecx
	jz end
	mov bl, BYTE [esi + ecx]
	test bl, bl
	jz end
	mov [edi + ecx], bl
	inc ecx
	jmp loop

end:
	pop rcx
	pop rbx
	mov rsp, rbp
	pop rbp
	ret
