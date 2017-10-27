BITS 64
CPU X64
	;;
	;; asm_strcasecmp - clone of strcasecmp function in x86 assembly
	;;
	;; Description: compares the two strings s1 and s2, ignoring the case of
	;; the characters.
	;;
	;; Prototype: int asm_strcasecmp(const char *s1, const char *s2);
	;; @s1: a pointer to the first string
	;; @s2: a pointer to the second string
	;; Return: It returns an integer less than, equal to, or greater than
	;; zero if s1 is found, respectively, to be less than, to match, or be
	;; greater than s2.
	;;
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
	cmp al, 0x40
	jna first
	or al, 0x20
	jmp first

downcase2:
	cmp bl, 0x40
	jna cmp
	or bl, 0x20
	jmp cmp
