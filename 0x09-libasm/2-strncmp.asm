BITS 64
CPU X64
	global asm_strncmp
	segment .text

asm_strncmp:
	push rbp
	mov rbp, rsp
	push rbx
	push rcx

	sub rsp, (2 * 8)

	mov QWORD [rbp - 0x18], rdi
	mov QWORD [rsp], rsi
	mov ecx, 0
	jmp start

loop:
	inc QWORD [rbp - 0x18]
	inc QWORD [rsp]
	inc ecx
start:
	mov rax, QWORD [rbp - 0x18]
	movzx eax, BYTE [rax]
	test al, al
	je subtract
	mov eax, 0
	cmp edx, ecx
	je end
	mov rax, QWORD [rbp - 0x18]
	movzx ebx, BYTE [rax]
	mov rax, QWORD [rsp]
	movzx eax, BYTE [rax]
	cmp bl, al
	je loop

subtract:
	mov rax, QWORD [rbp - 0x18]
	movzx eax, BYTE [rax]
	movzx ecx, al
	mov rax, QWORD [rsp]
	movzx eax, BYTE [rax]
	movzx eax, al
	sub ecx, eax

	cmp ecx, 0
	je is_zero
	jl less_than
	jg greater_than

end:
	add rsp, (2 * 8)
	pop rcx
	pop rbx
	mov rsp, rbp
	pop rbp
	ret

less_than:
	mov eax, -1
	jmp end

greater_than:
	mov eax, 1
	jmp end

is_zero:
	mov eax, 0
	jmp end
