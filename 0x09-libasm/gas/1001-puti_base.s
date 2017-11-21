	/*
	 * asm_puti_base - prints each digit of a signed number in the given base
	 * to STDOUT using the putc routine that prints one char at a time
	 *
	 * Prototype: size_t asm_puti_base(int n, const char *base);
	 * @n: the signed number to be printed
	 * @base: a string representing the base
	 * Return: the number of digits printed
	 */

	.text
	.globl asm_puti_base	# Define symbol to routine of the same name

asm_puti_base:			# Implement asm_put_base function/routine
	push %rbp		# Routine prologue, create new stack frame
	movq %rsp, %rbp
	pushq %rdx		# Save registers that will be overriden
	pushq %r8
	pushq %r9
	pushq %rdi		# Save first function argument
	movq %rsi, %rdi		# Use 2nd argument as the 1st to call strlen
	call asm_strlen		# Call to strlen, measure the length of string
	popq %rdi		# Restore 1st argument
	pushq %rax		# Save return value of strlen (length) to the stack
	lea (%rsp), %rdx	# Copy a pointer to the length of string (base)
	xorl %r9d, %r9d		# Start/reset our counter to the number of char printed
	movl %edi, %eax		# Copy 1st arg to check its sign (positive or negative)
	testl %eax, %eax
	js negative		# If negative jump to subroutine...
				# Otherwise continue to 'print' subroutine
print:				# Subroutine to print each digit
	movl (%rdx), %ebx	# Copy the length of string to ebx
	xorl %ecx, %ecx		# Start a counter
iloop:	xorl %edx, %edx		# Reset edx to make the division
	divl %ebx		# Divide the number (in edx:eax) by length of string
	sub $1, %rsp		# Reserve one byte on stack to put the remainder
	movb %dl, (%rsp)	# Save the remainder of division (number / length)
	incw %cx		# Increment our counter
	testl %eax, %eax	# Check when we reach zero
	jnz iloop		# While not zero, loop
pstr:	movzbl (%rsp), %r8d 	# After we reach zero start copying bytes from stack
	movzbl (%rsi, %r8), %edi # in reverse order to be printed
	call asm_putc		# Print each digit
	addb %al, %r9b		# Transfer the result of call to putc to our counter
	add $1, %rsp		# Restore each byte from the stack
	dec %cx			# Decrement our counter
	test %cx, %cx		# Check when we reach zero
	jnz pstr		# While not zero, loop
	mov %r9d, %eax 	   	# When zero, copy the acumulator to return value

end:
	addq $8, %rsp		# Remove 8 bytes from stack (used by rax)
	popq %r9		# Restore GPR (General Purpose Registers)
	popq %r8
	popq %rdx
	movq %rbp, %rsp		# Routine epilogue, return from stack frame
	popq %rbp
	retq

negative:			# Subroutine to deal with negative numbers
	negl %eax		# Make positive (flip sign)
	pushq %rax		# Preserve the number on stack
	movl $'-, %edi		# Define 1st arg to putc
	call asm_putc		# Call putc to print the minus sign
	addb %al, %r9b		# Add the return value to r9 to be returned later
	popq %rax		# Restore the number
	movl %eax, %edi		# Use the number as 1st argument to next routine
	jmp print		# Jump to 'print' subroutine
