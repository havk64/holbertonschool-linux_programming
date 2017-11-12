
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
	xorl %ecx, %ecx

loop:
	movzxb (%edi, %ecx), %eax
	cmpb $0x5b, %al
	jb downcase1
first:	movzxb (%esi, %ecx), %ebx
	cmpb $0x5b, %bl
	jb downcase2
cmp:	cmpb %bl, %al
	jnz diff
	inc %ecx
	test %al, %al
	jnz loop

end:
	popq %rcx
	popq %rbx
	movq %rbp, %rsp
	popq %rbp
	ret

diff:
	subl %ebx, %eax
	jmp end

downcase1:
	cmpb $0x40, %al
	jna first
	or $0x20, %al
	jmp first

downcase2:
	cmpb $0x40, %bl
	jna cmp
	or $0x20, %bl
	jmp cmp
