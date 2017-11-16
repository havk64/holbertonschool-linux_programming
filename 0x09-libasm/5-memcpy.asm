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
	global asm_memcpy

	segment .text

asm_memcpy:
	mov rax, rdi
	mov ecx, edx
	cld

rep	movsb
	ret
