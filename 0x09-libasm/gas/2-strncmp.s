	/*
	 * strncmp clone - return the difference between two strings
	 *
	 * Prototype: int asm_strncmp(const char *s1, const char *s2, size_t n);
	 * @s1: Pointer to the first string
	 * @s2: Pointer to the second string
	 * @n: the only first bytes to be compared
	 * Return: an integer that less than, equal to, or greater than zero if @s1  is
	 * found, respectively, to be less than, to match, or  be greater than s2.
	 *
	 * Implementation using just registers instead of variables on stack (memory)
	 */

	.global asm_strncmp

.text
asm_strncmp:
	pushq %rbp		# Routine preamble
	movq %rsp, %rbp
	pushq %rbx		# Save registers to be used
	pushq %rcx
	xorl %ecx, %ecx		# Start a counter

loop:
	cmpl %ecx, %edx		# Compare 'n' (3rd arg) with the counter
	jz equal		# If equal, break
	movzxb (%rdi, %rcx), %eax	# Char from first argument  (@s1)
	movzxb (%rsi, %rcx), %ebx	# Char from second argument (@s2)
	cmpb %bl, %al		# Compare characters
	jb less_than		# If less than, break
	ja greater_than		# If greater than, break
	inc %ecx		# Otherwise, increment the counter
	# Test if the s1 character is NULL (end of string)
	test %al, %al		# 'test' (bitwise &) is lighter than 'cmp'
	jnz loop		# If not NULL (zero) loop, otherwiser break

equal:
	movl $0, %eax		# If equal return zero

end:
	popq %rcx		# Restore registers used
	popq %rbx
	movq %rbp, %rsp		# Routine epilogue
	popq %rbp
	ret

less_than:
	movl $-1, %eax		# If first less than second return -1
	jmp end

greater_than:
	movl $1, %eax		# If first greater return 1
	jmp end
