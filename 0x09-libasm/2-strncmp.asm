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

loop:
	cmp edx, ecx		    ; Compare 'n' to the counter
	jz is_equal		    ; If equal, break
	movzx eax, BYTE [rdi + rcx] ; Char from first argument  (s1)
	movzx ebx, BYTE [rsi + rcx] ; Char from second argument (s2)
	cmp al, bl		    ; Compare characters
	jl less_than		    ; If less than, break
	jg greater_than		    ; If greater than, break
	inc ecx			    ; Otherwise, increment the counter
	;; Test if the s1 character is NULL (end of string)
	test al, al		    ; 'test' (bitwise &) is lighter than 'cmp'
	jnz loop		    ; If not NULL (zero) loop, otherwiser break

is_equal:
	mov eax, 0		; If equal return zero

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

