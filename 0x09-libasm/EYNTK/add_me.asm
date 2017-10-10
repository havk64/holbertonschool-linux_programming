BITS 64

	global add_me 		; Define and export the add_me symbol

	section .text		; Starts the .text (code) section/segment

add_me:				; Implement the code to add_me symbol
	mov eax, edi		; Copy the first argument to eax
	add eax, esi		; Add the second argument to the previous value
	ret			; Return
