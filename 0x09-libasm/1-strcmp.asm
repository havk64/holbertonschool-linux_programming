BITS 64
	global asm_strcmp

	segment .text
asm_strcmp:
	push rbp		; Routine preamble
	mov rbp, rsp
	push rdx		; Save registers to be used
	push rcx

	mov rcx, 0		; Start a counter
	jmp start		; Skip the first increment

loop:
	inc rcx			; Increment the counter
start:	movzx eax, BYTE [rdi + rcx] ; Test if s1 char is NULL
	test al, al		    ; 'test' is lighter than 'cmp'
	jz is_null		    ; If NULL exit from loop
	movzx edx, BYTE [rdi + rcx] ; Char from first argument
	movzx eax, BYTE [rsi + rcx] ; Char from second argument
	cmp dl, al		    ; If chars are equal keep looping
	jz loop
return:	jl less_than		; If first is less than second skip
	jg greater_than		; If greater skip
	jmp end			; Otherwise return

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

is_null:
	movzx eax, BYTE [rdi + rcx] ; If the first char is NULL check difference
	movzx edx, BYTE [rsi + rcx] ; and act accordingly (jump to 'return')
	sub al, dl
	cmp al, 0
	jmp return

