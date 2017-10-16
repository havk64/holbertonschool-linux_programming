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
	push rbp		; Routine preamble
	mov rbp, rsp
	push rbx		; Save registers to be used
	push rcx

	mov ecx, 0		; Start a counter
	jmp start		; Skip the first counter increment

loop:
	inc ecx			; Increment the counter
start:	movzx eax, BYTE [rdi + rcx] ; Test if s1 char is NULL
	test al, al		    ; 'test' (bitwise &) is lighter than 'cmp'
	je break		    ; If NULL (zero) break
	mov eax, 0		    ; Reset the return value
	cmp edx, ecx		    ; Compare 'n' to the counter
	je end			    ; If equal go to the end
	movzx ebx, BYTE [rdi + rcx] ; Char from first argument  (s1)
	movzx eax, BYTE [rsi + rcx] ; Char from second argument (s2)
	cmp bl, al		    ; If chars are equal keep looping
	je loop

break:
	movzx eax, BYTE [rdi + rcx] ; Check the difference between chars
	movzx ebx, BYTE [rsi + rcx]
	movzx eax, al
	sub al, bl

	cmp al, 0		; Act accordingly (jump to appropriate subroutine)
	je is_zero
	jl less_than
	jg greater_than

end:
	pop rcx			; Restore registers used
	pop rbx
	mov rsp, rbp		; Routine epilogue
	pop rbp
	ret

less_than:
	mov eax, -1		; If first less than second return -1
	jmp end

greater_than:
	mov eax, 1		; If first greater return 1
	jmp end

is_zero:
	mov eax, 0		; If equal return zero
	jmp end
