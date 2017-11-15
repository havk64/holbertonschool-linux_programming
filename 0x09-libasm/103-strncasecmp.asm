BITS 64
CPU X64

	;;
	;; asm_strncasecmp - clone of strncasecmp function in X86 Assembly
	;;
	;; Description:	compares the two strings @s1 and @s2, ignoring the case
	;; of the characters.
	;;
	;; Prototype: int asm_strncasecmp(const char *s1, const char *s2, size_t n);
	;; @s1: a pointer to the first string
	;; @s2: a pointer to the second string
	;; @n: the number of bytes to be compared
	;; Return: It returns an integer less than, equal to, or greater than
	;; zero if s1 is found, respectively, to be less than, to match, or be
	;; greater than s2.compare two strings ignoring case
	;;

	global asm_strncasecmp

segment .text
asm_strncasecmp:
	push rbp		; Routine preamble
	mov rbp, rsp
	push rbx		; Preserve register's state
	push rcx
	push r8
	xor ecx, ecx		; Clear the counter (zero)

loop:
	cmp edx, ecx		; When the counter is equal to @n...
	jz break		; Stop the loop
	movzx eax, BYTE [edi + ecx] ; Read @s1 character
	xor r8d, r8d		    ; Clear edx, start case check within range (A-Z)
	sub al, 'A'		    ; By subt the lower bound we skip one comparison
	cmp al, 'Z' - 'A'	    ; The only comparison needed  now is with max - min
	setbe r8b		    ; Using setxx we avoid unnecessary jumps
	shl r8b, 5		    ; Set the 6th bit to be activated case upper case
	or al, r8b		    ; Use *or* to activate the 6th bit/lower the case
	add al, 'A'		    ; Add back the 'min' of our range (A-Z)
	movzx ebx, BYTE [esi + ecx] ; Do the same with the second string @s2
	xor r8d, r8d
	sub bl, 'A'
	cmp bl, 'Z' - 'A'
	setbe r8b
	shl r8b, 5
	or bl, r8b
	add bl, 'A'
cmp:	cmp al, bl		; Check if they diff
	jnz diff		; If different jump
	inc ecx			; Otherwise increase the counter...
	test al, al		; While the char is not end of string (0)...
	jnz loop		; ...loop

end:
	pop r8
	pop rcx
	pop rbx
	mov rsp, rbp
	pop rbp
	ret

diff:
	sub eax, ebx
	jmp end

break:
	mov eax, 0
	jmp end
