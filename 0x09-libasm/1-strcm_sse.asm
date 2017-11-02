BITS 64

	global asm_strcmp_sse

section .text
asm_strcmp_sse:
	push rbp
	mov rbp, rsp
	sub rdi, rsi
	sub esi, 10h

loop:
	add esi, 10h
	movdqu xmm0, [esi]
	pcmpistri xmm0, [esi + edi], 11000b
	ja loop
	jc diff
	xor eax, eax
end:
	mov rsp, rbp
	pop rbp
	ret

diff:
	add edi, esi
	movzx eax, BYTE [edi + ecx]
	movzx edx, BYTE [esi + ecx]
	cmp al, dl
	jb less
	mov eax, 1
	jmp end

less:
	mov eax, -1
	jmp end

