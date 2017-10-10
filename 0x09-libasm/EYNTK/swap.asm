	BITS 64

	global swap		; Define the 'swap' symbol

	section .text		; Starts the .text segment/section


swap:				; Implement swap function
	push rbp		; Function preamble
	mov rbp, rsp

	push rdx		; Save the the registers in case they have value
	push rcx

	mov edx, dword [rdi]	; Swaping thw values using its value '[register]'
	mov ecx, dword [rsi]
	mov dword [rdi], ecx
	mov dword [rsi], edx

	pop rcx			; Restore the old values to registers
	pop rdx

	mov rsp, rbp		; Function prologue
	pop rbp

	ret			; Return
