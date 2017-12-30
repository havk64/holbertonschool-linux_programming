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
	push rbp
	mov rbp, rsp
	push rbx
	push rcx
	xor ecx, ecx
	mov rax, rdi

loop:
	cmp edx, ecx
	jz end
	mov bl, BYTE [esi + ecx]
	test bl, bl
	jz end
	mov [edi + ecx], bl
	inc ecx
	jmp loop

end:
	pop rcx
	pop rbx
	mov rsp, rbp
	pop rbp
	ret
