
	/*
	 * asm_strlen - clone of strlen function. Find the length of a string
	 * Gnu Assembler Syntax
	 *
	 * Prototype: size_t asm_strlen(const char *str);
	 * @str: a pointer to the string to be scanned
	 * Return: the number of bytes of the given string
	 *
	 * Implementation using SSE 4.2 text processing instructions where
	 * the string can be analyzed 16 bytes at a time thanks to the register size
	 * of 128 bits, granting great performance.
	 */

        .global asm_strlen      # Export the symbol to be used by external files

.text                           # Define the beginning of the .text (code) section
asm_strlen:                     # Define the asm_strlen routine
        pushq %rbp              # Routine prologue
        movq %rsp, %rbp
	pxor %xmm0, %xmm0
        movl $-16, %eax         # Initialize %eax to -16 to avoid one jmp

loop:
        addl $16,%eax           # Increment the counter by 16 each iteration
	pcmpistri $0b1000, (%edi, %eax, 1), %xmm0 # Look for the end of string
        jnz loop                           	  # and generates an index on %ecx

        addl %ecx, %eax         # Add the index to the counter to be returned
        movq %rbp, %rsp         # Routine epilogue
        popq %rbp
        ret

