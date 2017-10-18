BITS 64
CPU X64

	global asm_strchr

	segment .text

asm_strchr:
	push rbp
	mov rbp, rsp
	push rcx
	mov eax, edi
loop:
	movzx ecx, BYTE [rax]
	cmp ecx, esi
	jz end
	inc eax
	test cl, cl
	jz eos
	jmp loop

end:
	pop rcx
	mov rsp, rbp
	pop rbp
	ret

eos:	mov eax, 0
	jmp end
