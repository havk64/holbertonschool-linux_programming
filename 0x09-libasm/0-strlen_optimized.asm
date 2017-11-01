BITS 64

	;;
	;; asm_strlen_opt - Clone of strlen. Measure the length of a string
	;;
	;; Prototype: size_t asm_strlen(const char *str);
	;; @str: a pointer to the string to be scanned
	;; Return: the number of bytes of the given string
	;;
	;; Instead of test each character for the end of string this implementation
	;; tests each quadword (8 bytes) at a time to increase the performance.
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
	not ecx			; Invert ecx bits (-1), count backwards
	xor al, al		; Reset al to NULL (zero) for scasb instruction
	cld			; Clear direction flag, advances DI/SI
loop:	test rdi, 0x07		; Mask the address with 8 - 1 to check remainder
	jz next
	scasb			; Repeat 'scasb' until end of string + 1
	loopnz loop		; TODO - use loopnz
	jmp end
repeat:
	add rbx, 0x8		; Increment pointer to @str
	sub ecx, 0x8		; Count backwards
next:
	mov rax, [rbx]		; rax got the value (8 bytes) of @str
	sub rax, [lomagic]
	mov r8, [rbx]		; r8 got value (8 bytes) of @str
	not r8
	and r8, [himagic]
	test rax, r8
	jz repeat
end:	not ecx			; Invert ecx bits after the loop to get the length
	lea eax, [ecx - 1]

	pop rdi
	pop r8
	pop rbx
	mov rsp, rbp
	pop rbp
	ret
