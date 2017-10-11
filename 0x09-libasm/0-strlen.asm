BITS 64

	global asm_strlen
	segment .text

asm_strlen:
	push rbp
	mov rbp, rsp

	push rdx

	mov qword rdx, -1

loop:
	inc edx
	cmp byte [rdi + rdx], 0x0
	jne loop
	mov rax, rdx

	pop rdx

	mov rsp, rbp
	pop rbp
	ret

