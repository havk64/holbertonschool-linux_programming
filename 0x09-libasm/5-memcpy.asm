BITS 64
CPU X64
	;;
	;; asm_memcpy - a clone of memcpy in x86 Assembly
	;;
	;; Description:	The memcpy() function copies @n bytes from memory area
	;; @src to memory area @dest.
	;;
	;; @dest: a pointer to the destination string
	;; @src: a pointer to the source string
	;; @n: the number of bytes to be copied
	;; Return: a pointer to @dest string
	;;
	;; Prototype: void *asm_memcpy(void *dest, const void *src, size_t n);
	;;

	segment .text
	global asm_memcpy

asm_memcpy:
	mov rax, rdi		; Copy the pointer to @dest string to be returned
	mov ecx, edx		; Copy the length @n to the counter
	cld			; Clear the direction flag, DL in %eflags register
rep	movsb			; Copy @n bytes from ESI (source) to EDI (destination)
	ret			; Return
