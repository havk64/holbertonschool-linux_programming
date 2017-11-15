
	/*
	 * asm_strcasecmp - clone of strcasecmp function in x86 assembly
	 *
	 * Description: compares the two strings s1 and s2, ignoring the case of
	 * the characters.
	 *
	 * Prototype: int asm_strcasecmp(const char *s1, const char *s2);
	 * @s1: a pointer to the first string
	 * @s2: a pointer to the second string
	 * Return: It returns an integer less than, equal to, or greater than
	 * zero if s1 is found, respectively, to be less than, to match, or be
	 * greater than s2.
	 */

	.globl asm_strcasecmp

.text
asm_strcasecmp:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rbx
	pushq %rcx
	pushq %r8
	xorl %ecx, %ecx

loop:
	movzxb (%edi, %ecx), %eax
	leal -'A(%eax), %r9d
	cmpb $('Z - 'A), %r9b
	setbe %r8b
	shlb $5, %r8b
	orb %r8b, %al
	movzxb (%esi, %ecx), %ebx
	leal -'A(%ebx), %r8d
	cmpb $('Z - 'A), %r8b
	leal 0x20(%ebx), %r8d
	cmovbel %r8d, %ebx
	cmpb %bl, %al
	jnz diff
	inc %ecx
	test %al, %al
	jnz loop

end:
	popq %r8
	popq %rcx
	popq %rbx
	movq %rbp, %rsp
	popq %rbp
	retq

diff:
	subl %ebx, %eax
	jmp end
