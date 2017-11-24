
	/*
	 * asm_puts - a assembly routine that prints a string to STDOUT
	 *
	 * @str: a pointer to the string to be printed.
	 * Return: the number of bytes printed.
	 *
	 * Prototype: size_t asm_puts(const char *str);
	 */

	.text
	.globl asm_puts

asm_puts:
	pushq %rbp		# Routine prologue, set new stack frame
	movq %rsp, %rbp
	call asm_strlen		# Call asm_strlen to measure the string length
	movl %eax, %edx		# Use the length of the string as 3rd arg to write syscall
	movl %edi, %esi		# 2nd arg is the string
	movl $1, %edi		# 1st arg is the file descriptor to write to (1 for STDOUT)
	movl $1, %eax		# %eax carries the syscall number (1 for write)
	syscall
	movq %rbp, %rsp		# Routine epilogue, take down stack frame
	popq %rbp
	ret			# Return
