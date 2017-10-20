BITS 64

	global asm_strlen
	segment .text

asm_strlen:
	push rbp		; Function prologue
	mov rbp, rsp
	mov rax, 0		; Initialize the register counter
	jmp start

loop:
	inc rax
start:	cmp BYTE [rdi + rax], 0
	jnz loop		; End of the loop

	mov rsp, rbp		; Function epilogue
	pop rbp
	ret

