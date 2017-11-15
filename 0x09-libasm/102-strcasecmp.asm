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
	xor ecx, ecx		; Clear the counter (zero)

loop:
	movzx eax, BYTE [edi + ecx] ; Read @s1 character
	xor edx, edx		    ; Clear edx, start case check within range (A-Z)
	sub al, 'A'		    ; By subt the lower bound we skip one comparison
	cmp al, 'Z' - 'A'	    ; The only comparison needed  now is with max - min
	setbe dl		    ; Using setxx we avoid unnecessary jumps
	shl dl, 5		    ; Set the 6th bit to be activated case upper case
	or al, dl		    ; Use *or* to activate the 6th bit/lower the case
	add al, 'A'		    ; Add back the 'min' of our range (A-Z)
	movzx ebx, BYTE [esi + ecx] ; Do the same with the second string @s2
	xor edx, edx
	sub bl, 'A'
	cmp bl, 'Z' - 'A'
	setbe dl
	shl dl, 5
	or bl, dl
	add bl, 'A'
cmp:	cmp al, bl		; Check if they diff
	jnz diff		; If different jump
	inc ecx			; Otherwise increase the counter...
	test al, al		; While the char is not end of string (0)...
	jnz loop		; ...loop

end:
	pop rdx			; Restore register's state
	pop rcx
	pop rbx
	mov rsp, rbp		; Routine prologue
	pop rbp
	ret			; Return

diff:
	sub eax, ebx		; Check the different to return
	jmp end
