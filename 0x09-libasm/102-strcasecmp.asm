BITS 64
CPU X64
	;;
	;; asm_strcasecmp - clone of strcasecmp function in x86 assembly
	;;
	;; Description: compares the two strings s1 and s2, ignoring the case of
	;; the characters.
	;;
	;; Prototype: int asm_strcasecmp(const char *s1, const char *s2);
	;; @s1: a pointer to the first string
	;; @s2: a pointer to the second string
	;; Return: It returns an integer less than, equal to, or greater than
	;; zero if s1 is found, respectively, to be less than, to match, or be
	;; greater than s2.
	;;

	global asm_strcasecmp

segment .text
asm_strcasecmp:
	push rbp		; Routine preamble
	mov rbp, rsp
	push rbx		; Preserve register's state
	push rcx
	push r8
	xor ecx, ecx		; Clear the counter (zero)

loop:
	movzx eax, BYTE [edi + ecx] ; Read @s1 character and start case checking
	lea r8d, [eax - 'A']	    ; By subt the lower bound we skip one comparison
	cmp r8b, 'Z' - 'A'	    ; The only comparison needed  now is with max - min
	setbe r8b		    ; Using setxx we avoid unnecessary jumps
	shl r8b, 5		    ; Activate the 6th bit, if uppercase
	or al, r8b		    ; Use *or* to activate it and lower the case
	movzx ebx, BYTE [esi + ecx] ; Do the same with the second string @s2
	lea r8d, [ebx - 'A']
	cmp r8b, 'Z' - 'A'
	lea r8d, [ebx + 0x20]	; This time, instead of setxx I'm using LEA...
	cmovbe ebx, r8d		; and conditional move to lower the case (when upper)
	cmp al, bl		; Check if they diff (after converted to lower case)
	jnz diff		; If different jump
	inc ecx			; Otherwise increase the counter...
	test al, al		; While the char is not end of string (0)...
	jnz loop		; ...loop

end:
	pop r8			; Restore register's state
	pop rcx
	pop rbx
	mov rsp, rbp		; Routine prologue
	pop rbp
	ret			; Return

diff:
	sub eax, ebx		; Check the difference to return
	jmp end
