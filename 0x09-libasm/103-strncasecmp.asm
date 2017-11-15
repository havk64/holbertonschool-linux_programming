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
	push r8
	xor ecx, ecx

loop:
	cmp edx, ecx
	jz break
	movzx eax, BYTE [edi + ecx]
	xor r8d, r8d
	sub al, 'A'
	cmp al, 'Z' - 'A'
	setbe r8b
	shl r8b, 5
	or al, r8b
	add al, 'A'
	movzx ebx, BYTE [esi + ecx]
	xor r8d, r8d
	sub bl, 'A'
	cmp bl, 'Z' - 'A'
	setbe r8b
	shl r8b, 5
	or bl, r8b
	add bl, 'A'
cmp:	cmp al, bl
	jnz diff
	inc ecx
	test al, al
	jnz loop

end:
	pop r8
	pop rcx
	pop rbx
	mov rsp, rbp
	pop rbp
	ret

diff:
	sub eax, ebx
	jmp end

break:
	mov eax, 0
	jmp end
