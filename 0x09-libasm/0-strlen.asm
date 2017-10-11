BITS 64

	global asm_strlen
	segment .text

asm_strlen:
	push rbp
	mov rbp, rsp

	push rdx

	sub rsp, 0x8
	mov qword [rsp], -1
	mov dword edx, -1

loop:
	inc edx
	inc qword [rsp]
	cmp byte [edi + edx], 0x0
	jne loop
	mov qword rax, [rsp]

	add rsp, 0x8
	pop rdx

	mov rsp, rbp
	pop rbp
	ret

