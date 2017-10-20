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
start:	cmp BYTE [edi + eax], 0	; Compare each byte/char against zero
	jnz loop		; If not zero (NULL/End of string) keep counting

	mov rsp, rbp		; Function epilogue
	pop rbp
	ret

