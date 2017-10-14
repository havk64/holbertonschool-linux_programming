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
	jmp start

loop:
	add QWORD [rbp - 0x10], 1
	add QWORD [rsp], 1
start:
	mov rax, QWORD [rbp - 0x10]
	movzx eax, BYTE [rax]
	test al, al
	je subtract
	mov rax, QWORD [rbp - 0x10]
	movzx edx, BYTE [rax]
	mov rax, QWORD [rsp]
	movzx eax, BYTE [rax]
	cmp dl, al
	je loop

subtract:
	mov rax, QWORD [rbp - 0x10]
	movzx eax, BYTE [rax]
	movzx edx, al
	mov rax, QWORD [rsp]
	movzx eax, BYTE [rax]
	movzx eax, al
	sub edx, eax

	cmp edx, 0
	jl less_than
	jg greater_than

end:
	add rsp, (2 * 8)
	pop rdx

	mov rsp, rbp
	pop rbp
	ret

less_than:
	mov eax, -1
	jmp end

greater_than:
	mov eax, 1
	jmp end
