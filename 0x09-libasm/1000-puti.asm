BITS 64
CPU X64

	;; Prototype: size_t asm_puti(int n);

	global asm_puti
	extern asm_putc

segment .text
asm_puti:
	push rbp
	mov rbp, rsp
	push r9
	xor r9d, r9d
	mov eax, edi
	test eax, eax
	js negative
	jz zero
	call print
	jmp end

zero:
	mov dil, al
	or dil, 0x30
	call asm_putc
	jmp end

negative:
	neg eax
	push rax
	mov edi, '-'
	call asm_putc
	add r9b, al
	pop rax
	mov edi, eax
	call print
end:
	pop r9
	mov rsp, rbp
	pop rbp
	ret

	;; Prototype int print(int n);
print:
	push rbp
	mov rbp, rsp
	push rbx
	push rcx
	push r8
	sub rsp, 8
	lea rbx, [rsp]
	mov QWORD [rbx], 1
	sub rsp, 8
	lea rcx, [rsp]
	mov QWORD [rcx], rdi
	mov r8d, 10

calc:
	mov eax, [rcx]
	cmp eax, 10
	jb fdigit
	xor edx, edx
	div r8d
	mov [rcx], eax
	mov eax, [rbx]
	xor edx, edx
	mul r8d
	mov [rbx], eax
	jmp calc

fdigit:
	mov [rcx], rdi
iloop:	mov eax, [rcx]
	test eax, eax
	jz end2
	xor edx, edx
	div DWORD [rbx]
	mov dil, al
	or dil, 0x30
	call asm_putc
	mov [rcx], edx
	add r9b, al
	mov eax, [rbx]
	xor edx, edx
	div r8d
	mov [rbx], eax
	jmp iloop

end2:
	mov eax, r9d
	add rsp, 0x10
	pop r8
	pop rcx
	pop rbx
	mov rsp, rbp
	pop rbp
	ret
