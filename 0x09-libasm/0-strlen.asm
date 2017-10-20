BITS 64

	global asm_strlen
	segment .text

asm_strlen:
	push rbp		; Function prologue
	mov rbp, rsp
	xor eax, eax		; Initialize the counter
	jmp start		; Skip the first increment

loop:
	inc eax
start:	cmp BYTE [edi + eax], 0
	jnz loop		; End of the loop

	mov rsp, rbp		; Function epilogue
	pop rbp
	ret

