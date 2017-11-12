
	/*
	 * asm_putc - prints one character to STOUT
	 *
	 * Description: This routine uses the 'write' syscall to print the @c
	 * integer as a character to the STDOUT.
	 * The corresponding C implementation is:
	 *
	 * size_t putc(int c)
	 * {
	 * 	return (write(1, &c, 1));
	 * }
	 *
	 * @c: the character to be printed
	 * Return: the value return by the 'write' syscall
	 *
	 * Prototype: size_t asm_putc(int c);
	 */

	.globl asm_putc

.text
asm_putc:
	pushq %rbp		# Routine prologue, set new stack frame
	movq %rsp, %rbp
	pushq %rcx		# Save registers state/values
	pushq %rdx
	pushq %rsi
	pushq %rdi		# Copy the 1st arg to putc to the stack
	movl $1, %eax		# %eax carry the syscall number (1 for write)
	movl $1, %edx		# 3rd arg is the amount of bytes to be written
	leaq (%rsp), %rsi 	# 2nd arg is a pointer to the buffer to be printed
	movl $1, %edi		# 1st arg is the number of file descriptor (1 for STDOUT)
	syscall			# Call to 'write'
	popq %rdi		# Restore registers state/values
	popq %rsi
	popq %rdx
	popq %rcx
	movq %rbp, %rsp		# Routine epilogue, take down stack frame
	popq %rbp
	ret			# Return
