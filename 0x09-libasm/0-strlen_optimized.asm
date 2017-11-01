BITS 64

	;;
	;; asm_strlen_opt - Clone of strlen. Measure the length of a string
	;;
	;; Prototype: size_t asm_strlen(const char *str);
	;; @str: a pointer to the string to be scanned
	;; Return: the number of bytes of the given string
	;;
	;; Instead of test one character at a time for the end of string this
	;; implementation tests each quadword (8 bytes) at a time.
	;;

	global asm_strlen_opt

segment .rodata
himagic	dq 0x8080808080808080, 1
lomagic	dq 0x0101010101010101, 1

segment .text
asm_strlen_opt:
	push rbp
	mov rbp, rsp
	push rbx
	push r8
	push rdi
	mov rbx, rdi		; rbx got pointer to @str

	xor ecx, ecx		; Reset ecx to zero
	xor al, al		; Reset al to NULL (zero) for scasb instruction
	cld			; Clear direction flag, advances DI/SI
loop:	test rdi, 0x07		; Mask the address with 8 - 1 to check remainder (8 bytes align)
	jz next			; Jump to next when aligned
	inc cx			; Otherwise increment the counter
	scasb			; Repeat 'scasb' until end of string + 1
	jnz loop
	jmp end			; If end of string jump to end
repeat:
	add ecx, 0x8		; Count each 8 bytes
next:				; TODO - after find 0 verify where it was found and count
	mov rax, [rbx + rcx]	; rax got the value (8 bytes) of @str
	sub rax, [lomagic]
	mov r8, [rbx]		; r8 got value (8 bytes) of @str
	not r8
	and r8, [himagic]
	test rax, r8
	jz repeat
end:
	lea eax, [ecx]

	pop rdi
	pop r8
	pop rbx
	mov rsp, rbp
	pop rbp
	ret
