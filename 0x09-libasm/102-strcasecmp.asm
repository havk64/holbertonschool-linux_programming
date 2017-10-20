BITS 64
CPU X64
	;; Prototype: int asm_strcasecmp(const char *s1, const char *s2);
	global asm_strcasecmp

segment .text

asm_strcasecmp:
	push rbp
	mov rbp, rsp
	push rbx
	push rcx
	xor ecx, ecx

loop:
	movzx eax, BYTE [edi + ecx]
	cmp al, 91
	jb downcase1
first:	movzx ebx, BYTE [esi + ecx]
	cmp bl, 91
	jb downcase2
cmp:	cmp al, bl
	jnz diff
	inc ecx
	test al, al
	jnz loop

end:
	pop rcx
	pop rbx
	mov rsp, rbp
	pop rbp
	ret

diff:
	sub eax, ebx
	jmp end

downcase1:
	cmp al, 64
	jna first
	add al, 32
	jmp first

downcase2:
	cmp bl, 64
	jna cmp
	add bl, 32
	jmp cmp
