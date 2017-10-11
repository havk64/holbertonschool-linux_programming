BITS 64

	global asm_strlen
	segment .text

asm_strlen:
	push rbp		; Function prologue
	mov rbp, rsp

	push rdx		; Save the register to be used before

	mov qword rdx, -1	; Initialize the register counter

loop:
	inc edx
	cmp byte [rdi + rdx], 0x0
	jne loop		; End of the loop

	mov rax, rdx		; Copy the value of the counter to be returned

	pop rdx			; Restore rdx

	mov rsp, rbp		; Function epilogue
	pop rbp
	ret

