
	/*
	 * asm_strspn - clone of strspn function in X86 Assembly
	 *
	 * Description: calculates the length (in bytes) of the initial segment
	 * of @s which consists entirely of bytes in @accept.
	 *
	 * Prototype: size_t asm_strspn(const char *s, const char *accept);
	 * @s: a pointer to a string
	 * @accept: a pointer to a substring
	 * Return: the number of bytes in the initial segment of @s which consist
	 * only of bytes from @accept.
	 */

	.text
	.globl	asm_strspn

asm_strspn:
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
	ret

inner:
	xorl %edx, %edx
iloop:	movzbl (%esi, %edx), %r8d
	test %r8b, %r8b
	jz end
	incl %edx
	cmp %r8b, %bl
	jnz iloop
	jmp outter
