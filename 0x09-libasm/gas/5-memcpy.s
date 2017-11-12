
	/*
	 * asm_memcpy - a clone of memcpy in x86 Assembly
	 *
	 * Description:	The memcpy() function copies @n bytes from memory area
	 * @src to memory area @dest.
	 *
	 * @dest: a pointer to the destination string
	 * @src: a pointer to the source string
	 * @n: the number of bytes to be copied
	 * Return: a pointer to @dest string
	 *
	 * Prototype: void *asm_memcpy(void *dest, const void *src, size_t n);
	 */
	.globl asm_memcpy

.text
asm_memcpy:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rbx
	pushq %rcx
	xorl %ecx, %ecx
	movq %rdi, %rax

loop:
	cmpl %ecx, %edx
	jz end
	movb (%esi, %ecx), %bl
	test %bl, %bl
	movb %bl, (%edi, %ecx)
	inc %ecx
	jmp loop

end:
	popq %rcx
	popq %rbx
	movq %rbp, %rsp
	popq %rbp
	ret
