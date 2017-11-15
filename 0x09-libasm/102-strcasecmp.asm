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
	push rdx
	push r9
	xor ecx, ecx		; Clear the counter (zero)

loop:
	movzx eax, BYTE [edi + ecx] ; Read @s1 character
	xor edx, edx		    ; Clear edx, start case check within range (A-Z)
	lea r9d, [eax - 'A']	    ; By subt the lower bound we skip one comparison
	cmp r9b, 'Z' - 'A'	    ; The only comparison needed  now is with max - min
	setbe dl		    ; Using setxx we avoid unnecessary jumps
	shl dl, 5		    ; Set the 6th bit to be activated case upper case
	or al, dl		    ; Use *or* to activate the 6th bit/lower the case
	movzx ebx, BYTE [esi + ecx] ; Do the same with the second string @s2
	xor edx, edx
	lea r9d, [ebx - 'A']
	cmp r9b, 'Z' - 'A'
	lea edx, [ebx + 0x20]	; This time, instead of setxx I'm using LEA...
	cmovbe ebx, edx		; and conditional move to lower the case (when upper)
	cmp al, bl		; Check if they diff (after converted to lower case)
	jnz diff		; If different jump
	inc ecx			; Otherwise increase the counter...
	test al, al		; While the char is not end of string (0)...
	jnz loop		; ...loop

end:
	pop r9
	pop rdx			; Restore register's state
	pop rcx
	pop rbx
	mov rsp, rbp		; Routine prologue
	pop rbp
	ret			; Return

diff:
	sub eax, ebx		; Check the different to return
	jmp end
