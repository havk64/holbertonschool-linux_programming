	/*
	 * asm_strpbrk - clone of function strpbrk
	 *
	 * Description:	search a string for any of a set of bytes
	 *
	 * C Prototype: char *asm_strpbrk(const char *s, const char *accept);
	 * @s: a pointer to a string
	 * @accept: a pointer to a substring
	 * Return: a pointer to the byte in @s that matches one of the bytes
	 * in @accept, or NULL if no such byte is found.
	 */

	.text
	.globl asm_strpbrk

asm_strpbrk:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rbx
	pushq %rcx
	leal (%edi), %eax

loop:
	movzbl (%eax), %ebx
	testb %bl, %bl
	jz notfound
	xorl %ecx, %ecx
iloop:	movzbl (%esi, %ecx), %edx
	testb %dl, %dl
	jz outter
	incl %ecx
	cmpb %bl, %dl
	jz end
	jmp iloop
outter:	incl %eax
	jmp loop

notfound:
	xorl %eax, %eax
end:	popq %rcx
	popq %rbx
	movq %rbp, %rsp
	popq %rbp
	retq

