BITS 64
	;;
	;; strcmp clone - return the difference between two strings
	;;
	;; Prototype: int asm_strcmp(const char *s1, const char *s2);
	;; @s1: Pointer to the first string
	;; @s2: Pointer to the second string
	;; Return: an integer that less than, equal to, or greater than zero if s1  is
	;; found, respectively, to be less than, to match, or  be greater than s2.
	;;
	;; Implementation using just registers instead of variables on stack (memory)
	;;

	global asm_strcmp

	segment .text

asm_strcmp:
	push rbp		; Routine preamble
	mov rbp, rsp
	push rdx		; Save registers to be used
	push rcx
	mov rcx, 0		; Start a counter

loop:

	movzx edx, BYTE [rdi + rcx] ; Char from first argument  (s1)
	movzx eax, BYTE [rsi + rcx] ; Char from second argument (s2)
	cmp dl, al		    ; Compare values
	jl less_than		; If first is less than second skip
	jg greater_than		; If greater skip
	inc rcx			; Otherwise increment the counter
	;; Test if the s1 character is NULL (end of string)
	test al, al		; 'test' (bitwise &) is lighter than 'cmp'
	jz is_equal		; If end of string (zero) exit from loop
	jmp loop		; Otherwise keep looping

is_equal:
	mov eax, 0
	jmp end

less_than:
	mov eax, -1		; If first less than second return -1
	jmp end			; and Return

greater_than:
	mov eax, 1		; If first is greater return 1 and return

end:
	pop rcx			; Restore used registers
	pop rdx
	mov rsp, rbp		; Routine epilogue
	pop rbp
	ret


