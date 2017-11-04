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
	ja short loop
	jc short diff
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
	setb bl
	neg ebx
	mov eax, ebx
	and eax, -1
	not ebx
	and ebx, 1
	or eax, ebx
	jmp short end

