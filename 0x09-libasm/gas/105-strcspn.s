
	/*
	 * asm_strcspn - clone of strcsnp in x86 Assembly
	 *
	 * Description:	calculates the length of the initial segment of @s which
	 * consists entirely of bytes not in @reject.
	 *
	 * Prototype: size_t asm_strcspn(const char *s, const char *reject);
	 * @s: a pointer to a string
	 * @reject: a pointer to a substring
	 * Return: the number of bytes in the initial segment of @s which are
	 * not in the string @reject.
	 */

	.text
	.globl asm_strcspn

asm_strcspn:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rbx
	pushq %rcx
	pushq %rdx
	xorl %eax, %eax
	xorl %ecx, %ecx

loop:
	movzbl (%edi, %ecx), %ebx
	testb %bl, %bl
	jz end
	jmp inner
outter:	incl %eax
	incl %ecx
	jmp loop

end:
	popq %rdx
	popq %rcx
	popq %rbx
	movq %rbp, %rsp
	popq %rbp
	retq

inner:
	xorl %edx, %edx
iloop:	movzbl (%esi, %edx), %r8d
	testb %r8b, %r8b
	jz outter
	incl %edx
	cmp %r8b, %bl
	jz end
	jmp iloop
