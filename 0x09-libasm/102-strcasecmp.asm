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
	push rdx
	xor ecx, ecx

loop:
	movzx eax, BYTE [edi + ecx]
	xor edx, edx
	sub al, 'A'
	cmp al, 'Z' - 'A'
	setb dl
	shl dl, 5
	or al, dl
	add al, 'A'
	movzx ebx, BYTE [esi + ecx]
	xor edx, edx
	sub bl, 'A'
	cmp bl, 'Z' - 'A'
	setb dl
	shl dl, 5
	or bl, dl
	add bl, 'A'
cmp:	cmp al, bl
	jnz diff
	inc ecx
	test al, al
	jnz loop

end:
	pop rdx
	pop rcx
	pop rbx
	mov rsp, rbp
	pop rbp
	ret

diff:
	sub eax, ebx
	jmp end
