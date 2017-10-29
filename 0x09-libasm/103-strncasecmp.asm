BITS 64
CPU X64

	;;
	;; asm_strncasecmp - clone of strncasecmp function in X86 Assembly
	;;
	;; Description:	compares the two strings @s1 and @s2, ignoring the case
	;; of the characters.
	;;
	;; Prototype: int asm_strncasecmp(const char *s1, const char *s2, size_t n);
	;; @s1: a pointer to the first string
	;; @s2: a pointer to the second string
	;; @n: the number of bytes to be compared
	;; Return: It returns an integer less than, equal to, or greater than
	;; zero if s1 is found, respectively, to be less than, to match, or be
	;; greater than s2.compare two strings ignoring case
	;;

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
