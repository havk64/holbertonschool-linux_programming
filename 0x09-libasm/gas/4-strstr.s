
	/*
	 * asm_strstr - a clone of strstr function
	 *
	 * Description:	the strstr() function finds the first occurrence of the
	 * substring @sub in the string @s.
	 *
	 * @s: the pointer to the string
	 * @sub: a pointer to the substring to be searched for
	 * Return: a pointer to the beginning of the substring,
	 * or NULL if substring is not found.
	 *
	 * Prototype: char *asm_strstr(const char *s, char *sub);
	 */

	.globl asm_strstr

.text
asm_strstr:
	pushq %rbp
	movq %rsp, %rbp
	pushq %rbx
	pushq %rcx
	pushq %rdx

loop:
	movzxb (%edi), %eax
	cmpb (%esi), %al
	jz match
	inc %edi
	test %al, %al
	jnz loop
	xorl %eax, %eax

end:
	popq %rdx
	popq %rcx
	popq %rbx
	movq %rbp, %rsp
	popq %rbp
	ret

match:
	movl %edi, %eax
	xorl %ecx, %ecx
substr:
	inc %ecx
	movb (%edi, %ecx), %bl
	movb (%esi, %ecx), %dl
	test %dl, %dl
	jz end
	cmpb %dl, %bl
	jz substr
	inc %edi
	jmp loop
