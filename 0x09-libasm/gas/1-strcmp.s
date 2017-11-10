
	/*
	 * strcmp clone - return the difference between two strings
	 *
	 * Prototype: int asm_strcmp(const char *s1, const char *s2);
	 * @s1: Pointer to the first string
	 * @s2: Pointer to the second string
	 * Return: an integer that less than, equal to, or greater than zero if s1  is
	 * found, respectively, to be less than, to match, or  be greater than s2.
	 *
	 * Implementation using just registers instead of variables on stack (memory)
	 */

	.global asm_strcmp

.text
asm_strcmp:
	pushq %rbp		# Routine preamble
	movq %rsp, %rbp
	pushq %rbx		# Save registers to be used
	pushq %rcx
	xorl %ecx, %ecx		# Start a counter

loop:
	movzxb (%edi, %ecx), %eax # Char from first argument  (@s1)
	movzxb (%esi, %ecx), %ebx # Char from second argument (@s2)
	cmpb %bl, %al		# Compare values
	jb less_than		# If first is less than second skip
	ja greater_than		# If greater skip
	inc %ecx		# Otherwise increment the counter
	# Test if the s1 character is NULL (end of string)
	testb %al, %al		# 'test' (bitwise &) is lighter than 'cmp'
	jnz loop		# If not zero loop, otherwise continue (end)

end:
	popq %rcx		# Restore used registers
	popq %rbx
	movq %rbp, %rsp		# Routine epilogue
	popq %rbp
	ret

less_than:
	movl $-0x1, %eax	# If first less than second return -1
	jmp end			# and Return

greater_than:
	movl $0x1, %eax		# If first is greater return 1 and return
	jmp end


