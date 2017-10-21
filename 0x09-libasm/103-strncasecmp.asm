BITS 64
CPU X64

	;; Prototype: int asm_strncasecmp(const char *s1, const char *s2, size_t n);
	global asm_strncasecmp

segment .text
asm_strncasecmp:
	push rbp
	mov rbp, rsp
	push rbx
	push rcx
	xor ecx, ecx

loop:
	cmp edx, ecx
	jz break
	movzx eax, BYTE [edi + ecx]
	cmp al, 0x5b
	jb downcase1
first:	movzx ebx, BYTE [esi + ecx]
	cmp bl, 0x5b
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
	cmp al, 0x40
	jna first
	or al, 0x20
	jmp first

downcase2:
	cmp bl, 0x40
	jna cmp
	or bl, 0x20
	jmp cmp

break:
	mov eax, 0
	jmp end
