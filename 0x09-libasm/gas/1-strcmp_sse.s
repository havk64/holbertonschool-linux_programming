	/*
	 * strcmp clone - return the difference between two strings
	 *
	 * Implementation: Using SSE 4.2 text processing instructions where
	 * the string are analyzed 16 bytes at a time thanks to the register size
	 * of 128 bits, granting great performance.
	 * Also avoid conditional jump to allow 'Speculative Execution', a feature
	 * available in modern processors that uses its parallel processing
	 * capabilities.
	 *
	 * Prototype: int asm_strcmp(const char *s1, const char *s2);
	 * @s1: Pointer to the first string
	 * @s2: Pointer to the second string
	 * Return: an integer that less than, equal to, or greater than zero if s1  is
	 * found, respectively, to be less than, to match, or  be greater than s2.
	 */

	.global asm_strcmp_sse

.text
asm_strcmp_sse:
	pushq %rbp		# Routine prologue
	movq %rsp, %rbp
	subq %rsi, %rdi		# Reduce effectively to just one index (rsi)
	subl $0x10, %esi	# Sub 16 bytes, avoid jump first `add` instruction

loop:
	addl $0x10, %esi	# Increment 16 bytes (128 bits) at a time
	movdqu (%esi), %xmm0	# Load 16 bytes from addr in esi into xmm0 (unaligned)
	pcmpistri $0b11000, (%esi, %edi, 1), %xmm0 # Compare the two strings
	ja loop			# While equal keep iterating
	jc diff			# If they differ return the index in ecx and jump
	xorl %eax, %eax		# Otherwise they are equal, return 0
end:
	movq %rbp, %rsp		# Routine epilogue
	popq %rbp
	ret			# Return

diff:				# Replace conditional jumps with 'setcc' instruction
	addl %esi, %edi		# Add back the address of edi
	movzbl (%edi, %ecx), %eax	# Read the two strings at index (ecx)
	cmpb (%esi, %ecx), %al	# Compare the characters
	setbb %bl		# Set 1 into bl case al < dl => bl = (al < dl) ? 1 : 0
	negl %ebx		# Two's complement: ebx = (al < dl) ? 0xffffff : 0
	movl %ebx, %eax		# eax = (al < dl) ? 0xffffff : 0
	andl $-1, %eax		# eax = (al < dl) ? 0xffffff : 0
	notl %ebx		# ebx = (al < dl) ? 0 : 0xffffff
	andl $1, %ebx		# ebx = (al < dl) ? 0 : 1
	orl %ebx, %eax		# eax = (al < dl) ? 0xffffff : 1 (-1 or 1)
	jmp end			# Go to the end and return

