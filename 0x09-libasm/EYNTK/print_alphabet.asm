BITS 64

	global print_alphabet

	section .text

print_alphabet:
	push rbp		; Funcion prologue
	mov rbp, rsp

	push rsi		; Save registers to the stack
	push rax
	push rdi
	push rdx

	sub rsp, 1		; Make room to our char variable (one byte)

	;; Prepare the system call
	mov eax, 1		; Number of write system call
	mov edi, 1		; Print to the STDOUT
	mov rsi, rsp		; The address to read from
	mov edx, 1		; Size to be written, one byte at a time

	mov byte [rsp], 0x61	; Write the letter 'a' (97) to our char variable

loop:				; Loop instructions
	syscall
	inc byte [rsp]		; Increment by one
	cmp byte [rsp], 0x7a	; Compare with the target end
	jle loop		; While not in the target loop
	;; End of the loop

	add rsp, 1		; Free the space used by our variable

	pop rdx			; Restore register's values
	pop rdi
	pop rax
	pop rsi

	mov rsp, rbp		; Function epilogue
	pop rbp
	ret


