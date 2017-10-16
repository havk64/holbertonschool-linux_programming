BITS 64
CPU X64
	;;
	;; strncmp clone - return the difference between two strings
	;;
	;; Prototype: int asm_strncmp(const char *s1, const char *s2, size_t n);
	;; @s1: Pointer to the first string
	;; @s2: Pointer to the second string
	;; @n: the only first bytes to be compared
	;; Return: an integer that less than, equal to, or greater than zero if s1  is
	;; found, respectively, to be less than, to match, or  be greater than s2.
	;;
	;; Implementation using just registers instead of variables on stack (memory)
	;;

	global asm_strncmp
	segment .text

asm_strncmp:
	push rbp
	mov rbp, rsp
	push rbx
	push rcx

	mov ecx, 0
	jmp start

loop:
	inc ecx
start:
	movzx eax, BYTE [rdi + rcx]
	test al, al
	je subtract
	mov eax, 0
	cmp edx, ecx
	je end
	movzx ebx, BYTE [rdi + rcx]
	movzx eax, BYTE [rsi + rcx]
	cmp bl, al
	je loop

subtract:
	movzx eax, BYTE [rdi + rcx]
	movzx ebx, BYTE [rsi + rcx]
	movzx eax, al
	sub al, bl

	cmp al, 0
	je is_zero
	jl less_than
	jg greater_than

end:
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
