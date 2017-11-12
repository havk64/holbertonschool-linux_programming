
	/*
	 * asm_strncasecmp - clone of strncasecmp function in X86 Assembly
	 *
	 * Description:	compares the two strings @s1 and @s2, ignoring the case
	 * of the characters.
	 *
	 * Prototype: int asm_strncasecmp(const char *s1, const char *s2, size_t n);
	 * @s1: a pointer to the first string
	 * @s2: a pointer to the second string
	 * @n: the number of bytes to be compared
	 * Return: It returns an integer less than, equal to, or greater than
	 * zero if s1 is found, respectively, to be less than, to match, or be
	 * greater than s2.compare two strings ignoring case
	 */

	.globl asm_strncasecmp

.text
asm_strncasecmp:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rbx
	pushq %rcx
	xorl %ecx, %ecx

loop:
	cmpl %ecx, %edx
	jz break
	movzxb (%edi, %ecx), %eax
	cmpb $0x5b, %al
	jb downcase1
first:	movzxb (%esi, %ecx), %ebx
	cmpb $0x5b, %bl
	jb downcase2
cmp:	cmpb %bl, %al
	jnz diff
	incl %ecx
	testb %al, %al
	jnz loop

end:
	popq %rcx
	popq %rbx
	movq %rbp, %rsp
	popq %rbp
	retq

diff:
	subl %ebx, %eax
	jmp end

downcase1:
	cmpb $0x40, %al
	jna first
	orb $0x20, %al
	jmp first

downcase2:
	cmpb $0x40, %bl
	jna cmp
	or $0x20, %bl
	jmp cmp

break:
	xorl %eax, %eax
	jmp end
