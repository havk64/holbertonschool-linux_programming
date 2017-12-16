
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

	.text
	.globl asm_strcasecmp

asm_strcasecmp:
	pushq %rbp		# Routine preamble
	movq %rsp, %rbp
	pushq %rbx		# Preserve register's state
	pushq %rcx
	pushq %r8
	xorl %ecx, %ecx		# Reset the counter

loop:
	movzxb (%edi, %ecx), %eax #  Read @s1 character and start case checking
	leal -'A(%eax), %r9d	  #  By subt the lower bound we skip one comparison
	cmpb $('Z - 'A), %r9b	  #  The only comparison needed  now is with max - min
	setbe %r8b		  #  Using setxx we avoid unnecessary jumps
	shlb $5, %r8b		  #  Activate the 6th bit, if uppercase
	orb %r8b, %al		  #  Use *or* to activate it and lower the case
	movzxb (%esi, %ecx), %ebx # 	 Do the same with the second string @s2
	leal -'A(%ebx), %r8d
	cmpb $('Z - 'A), %r8b
	leal 0x20(%ebx), %r8d	# This time, instead of setxx I'm using LEA...
	cmovbel %r8d, %ebx	# and conditional move to lower the case (when upper)
	cmpb %bl, %al		# Check if they diff (after converted to lower case)
	jnz diff		# If different jump
	inc %ecx		# Otherwise increase the counter...
	test %al, %al		# While the char is not end of string (0)...
	jnz loop		# ...loop

end:
	popq %r8		# Restore register's state       Restore register's state

	popq %rcx
	popq %rbx
	movq %rbp, %rsp		# Routine prologue
	popq %rbp
	retq			# Return

diff:
	subl %ebx, %eax		# Check the difference to return
	jmp end
