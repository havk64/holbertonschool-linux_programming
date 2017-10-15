BITS 64
	global asm_strcmp

	segment .text
asm_strcmp:
	push rbp
	mov rbp, rsp
	push rdx
	push rcx

	mov rcx, 0
	jmp start

loop:
	inc rcx
start:
	movzx eax, BYTE [rdi + rcx]
	test al, al
	jz subtract
	movzx edx, BYTE [rdi + rcx]
	movzx eax, BYTE [rsi + rcx]
	cmp dl, al
	jz loop

subtract:
	movzx eax, BYTE [rdi + rcx]
	movzx edx, al
	movzx eax, BYTE [rsi + rcx]
	movzx eax, al
	cmp edx, eax
	jl less_than
	jg greater_than

end:
	pop rcx
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
