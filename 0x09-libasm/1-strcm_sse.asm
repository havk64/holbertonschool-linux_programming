BITS 64
	;;
	;; strcmp clone - return the difference between two strings
	;;
	;; Implementation: Using SSE 4.2 text processing instructions where
	;; the string are analyzed 16 bytes at a time thanks to the register size
	;; of 128 bits, granting great performance.
	;; Also avoid conditional jump to allow 'Speculative Execution', a feature
	;; available in modern processors that uses its parallel processing
	;; capabilities.
	;;
	;; Prototype: int asm_strcmp(const char *s1, const char *s2);
	;; @s1: Pointer to the first string
	;; @s2: Pointer to the second string
	;; Return: an integer that less than, equal to, or greater than zero if s1  is
	;; found, respectively, to be less than, to match, or  be greater than s2.
	;;

	global asm_strcmp_sse

section .text
asm_strcmp_sse:
	push rbp		; Routine prologue
	mov rbp, rsp
	sub rdi, rsi		; Reduce effectively to just one index (rsi)
	sub esi, 10h		; Sub 16 bytes, avoid jump first `add` instruction

loop:
	add esi, 10h		; Increment 16 bytes (128 bits) at a time
	movdqu xmm0, [esi]	; Load 16 bytes from addr in esi into xmm0 (unaligned)
	pcmpistri xmm0, [esi + edi], 11000b ; Check diff between the two strings
	ja short loop			    ; While equal keep iterating
	jc short diff		; If they differ return the index in ecx and jump
	xor eax, eax		; Otherwise they are equal, return 0
end:
	mov rsp, rbp		; Routine epilogue
	pop rbp
	ret			; Return

diff:				; Replace jump with 'setcc' instruction
	add edi, esi		; Add back the address of edi
	movzx eax, BYTE [edi + ecx] ; Read the two strings at index (ecx)
	movzx edx, BYTE [esi + ecx]
	cmp al, dl		; Compare the characters
	setb bl			; setb puts 1 into bl case al < dl => bl = (al < dl) ? 1 : 0
	neg ebx			; Two's complement: ebx = (al < dl) ? 0xffff : 0
	mov eax, ebx		; eax = (al < dl) ? 0xffff : 0
	and eax, -1		; eax = (al < dl) ? 0xffff : 0
	not ebx			; ebx = (al < dl) ? 0 : 0xffff
	and ebx, 1		; ebx = (al < dl) ? 0 : 1
	or eax, ebx		; eax = (al < dl) ? 0xffff : 1 (-1 or 1)
	jmp short end		; Go to the end and return

