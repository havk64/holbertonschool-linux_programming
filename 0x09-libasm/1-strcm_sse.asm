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
	push rbp
	mov rbp, rsp
	sub rdi, rsi
	sub esi, 10h

loop:
	add esi, 10h
	movdqu xmm0, [esi]
	pcmpistri xmm0, [esi + edi], 11000b
	ja short loop
	jc short diff
	xor eax, eax
end:
	mov rsp, rbp
	pop rbp
	ret

diff:
	add edi, esi
	movzx eax, BYTE [edi + ecx]
	movzx edx, BYTE [esi + ecx]
	cmp al, dl
	setb bl
	neg ebx
	mov eax, ebx
	and eax, -1
	not ebx
	and ebx, 1
	or eax, ebx
	jmp short end

