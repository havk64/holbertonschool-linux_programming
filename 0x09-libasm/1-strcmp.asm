BITS 64
	global asm_strcmp

	segment .text
asm_strcmp:
	push rbp
	mov rbp, rsp

	push rdx
	sub rsp, (2 * 8)

	mov QWORD [rbp - 0x10], rdi
	mov QWORD [rsp], rsi
	jmp first

loop:
	add QWORD [rbp - 0x10], 1
	add QWORD [rsp], 1
first:
	mov rax, QWORD [rbp - 0x10]
	movzx eax, BYTE [rax]
	test al, al
	je end
	mov rax, QWORD [rbp - 0x10]
	movzx edx, BYTE [rax]
	mov rax, QWORD [rsp]
	movzx eax, BYTE [rax]
	cmp dl, al
	je loop
end:
	mov rax, QWORD [rbp - 0x10]
	movzx eax, BYTE [rax]
	movzx edx, al
	mov rax, QWORD [rsp]
	movzx eax, BYTE [rax]
	movzx eax, al
	sub edx, eax
	mov eax, edx

	add rsp, (2 * 8)
	pop rdx

	pop rbp
	mov rsp, rbp
	ret
