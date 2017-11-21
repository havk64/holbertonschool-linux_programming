	/*
	 * asm_puti - print each digit of a signed base 10 number to STDOUT using
	 * asm_putc routine (defined in the 100-putc.asm file)
	 *
	 * Prototype: size_t asm_puti(int n);
	 * @n: the base 10 number to be printed
	 */

	.text
	.globl asm_puti		# Define and export asm_puti symbol

asm_puti:			# Implement the asm_puti function/routine
	pushq %rbp		# Routine prologue, create new stack frame
	movq %rsp, %rbp
	pushq %rbx		# Save registers to be used
	pushq %rcx
	pushq %rdx
	pushq %r8
	xorl %r8d, %r8d		# Reset 32 bits version of r8 register, our accumulator
	mov %edi, %eax		# Copy 1st arg (number) to %eax
	testl %eax, %eax	# Check the number sign
	js negative		# If negative jump to subroutine
num2str:			# Subroutine to convert number to string
	mov $10, %ebx		# Copy the divisor to %ebx
	xorl %ecx, %ecx		# Start a counter
pushd:	xorl %edx, %edx		# Zero edx register used in the division
	divl %ebx		# Divide the number (in eax) by 10
	sub $1, %rsp		# Reserve on byte on stack
	movb %dl, (%rsp)	# Save the remainder of the division to this byte
	incw %cx		# Increment the counter
	testl %eax, %eax	# Check when it reach zero
	jnz pushd		# While not zero, loop
print:	movzbl (%rsp), %edi	# Start retrieving each byte from stack, reverse order
	orb $0x30, %dil		# Add 48 to each digit to convert it to an ASCII character
	call asm_putc		# Call the routine to print each digit
	addb %al, %r8b		# Add the return value of function call to the accumulator
	add $1, %rsp		# Remove each byte from stack
	dec %cx			# Decrease the counter
	testw %cx, %cx		# Check when it reach zero
	jnz print		# While not zero, loop
	movl %r8d, %eax		# Transfer the accumulator to eax (return value)
end:
	popq %r8		# Restore registers
	popq %rdx
	popq %rcx
	popq %rbx
	movq %rbp, %rsp		# Routine epilogue, take down the stack frame
	popq %rbp
	retq

negative:			# Subroutine to deal with negative numbers
	negl %eax		# Flip sign
	pushq %rax		# Save the number to the stack
	movl $'-, %edi		# Prepare 1st function argument
	call asm_putc		# Call putc to print the minus sign
	add %al, %r8b	 	# Add the return value to the accumulator
	popq %rax		# Retrieve the number from stack
	movl %eax, %edi		# Copy it to edi (1st argument to func call)
	jmp num2str		# Jump to num2str subroutine
