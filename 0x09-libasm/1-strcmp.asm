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
	jz is_null
	movzx edx, BYTE [rdi + rcx]
	movzx eax, BYTE [rsi + rcx]
	cmp dl, al
	jz loop
return:	jl less_than
	jg greater_than
	jmp end

less_than:
	mov eax, -1
	jmp end

greater_than:
	mov eax, 1

end:
	pop rcx
	pop rdx
	mov rsp, rbp
	pop rbp
	ret

is_null:
	movzx eax, BYTE [rdi + rcx]
	movzx edx, BYTE [rsi + rcx]
	sub al, dl
	cmp al, 0
	jmp return

