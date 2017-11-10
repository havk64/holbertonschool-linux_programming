
	/*
	 * asm_strchr - clone of strchr (3) function
	 *
	 * Description:	The strchr() function returns a pointer to the first
	 * occurrence of the character @c in the string @s.
	 *
	 * @s: a pointer to the string to scanned
	 * @c: a character to be searched for
	 * Return: a pointer to the matched character or
	 * NULL if the character is not found.
	 * Prototype: char *asm_strchr(const char *s, int c);
	 */

	.global asm_strchr

.text
asm_strchr:
	pushq %bp		# Routine prologue
	movq %rsp, %rbp
	pushq %cx		# Save register to be used
	movl %edi, %eax		# Copy the first function argument to %eax register
loop:
	movzxb (%eax), %ecx	# Read one byte of the string to low byte of %ecx
	cmpl %esi, %ecx		# Compare it agains the second argument
	jz end			# If they are equal jump to the end (returning %eax)
	test %cl, %cl		# Test if the byte/char is NULL (end of string)
	jz eos			# If NULL jump to 'eos' symbol
	inc %eax		# Otherwise increment the pointer to the string
	jmp loop		# ...and loop again

end:
	pop %rcx		# Routine epilogue
	mov %rbp, %rsp
	pop %rbp
	ret

eos:	mov $0, %eax		# If end of string return 0
	jmp end
