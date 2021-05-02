section .data
	badchrs db 43, 9, 10, 11, 45, 12, 13, 32, 0
	; \t, \n, \v, \f, \r, SPACE

section .text
	extern ft_strlen
	global checkbase

	countchr: ; chr, str
		push rsi
		mov rax, 0
		loop00:
			mov cl, [rsi]
			cmp dil, cl
			jne skipchr
			add rax, 1
		skipchr:
			inc rsi
			cmp cl, 0
			jne loop00
			pop rsi
			ret

	checkmaxchrs: ; rdi:str, rsi:chrs, rdx:maxnbr
		push r8 ; > r8
		push r9 ; > r9 > r8
		mov r8, rsi ; r8:chrs[0]
		mov r9, r8 ; r9:chrs[0] sav	
		mov rsi, rdi 	; rsi:str
		loop01:
			mov dil, [r8]	; dil:chrs[x]
			cmp dil, 0		; end of chrs ?
			je true01		; ret 1
			call countchr
			cmp rax, rdx	; count of chrs[x] in str > maxnbr?
			jg false01		; ret 0
			inc r8			; x++
			jmp loop01
		true01:
			mov rax, 1
			jmp end01
		false01:
			mov rax, 0
		end01:
			mov rdi, rsi	; rdi:str
			mov rsi, r9		; rsi:chrs[0]
			pop r9 ; < r9 < r8
			pop r8 ; < r8
			ret


	checkbase: ; rdi:base
		push rsi ; > rsi
		push rdx ; > rdx > rsi
		call ft_strlen	; chk base
		cmp rax, 1		; sz
		jle false02		; ret 0

		mov rsi, rdi ; rdi:base, rsi: base
		mov rdx, 1	; musn't have dub chr in base
		call checkmaxchrs
		cmp rax, 0
		je false02
		mov rsi, badchrs	; rdi: base, rsi: badchrs
		mov rdx, 0			; musn't have any badchrs in base
		call checkmaxchrs
		cmp rax, 0
		je false02
		mov rax, 1
		jmp end02
		false02:
			mov rax, 0
		end02:
			pop rdx ; < rdx < rsi
			pop rsi ; < rsi
			ret

	get_index: ; rdi:char, rsi:base
		push rsi ; > rsi
		push rbx ; > rbx > rsi
		mov rax, 0
		loop03:
			mov bl, [rsi]
			cmp bl, 0
			je false03
			cmp dil, bl
			je end03
			inc rsi
			add rax, 1
			jmp loop03
		false03:
			mov rax, -1
		end03:
		pop rbx ; < rbx < rsi
		pop rsi ; < rsi
		ret

	
;	ft_atoi_base:	; rdi:str, rsi:base
;		push rbx ; > rbx
;		push rcx ; > rcx > rbx
;		push rdx ; > rdx > rcx > rbx
;		push r9 ; > r9 > rdx > rcx > rbx
;		mov rdx, 1
;		mov rcx, rdi ; sav rdi:str
;		mov rbx, 0
;		call ft_strlen
;		cmp rax, 0
;		je end05
;		mov rdi, rsi ; rdi:base
;		call checkbase
;		cmp rax, 0
;		je end05
;		call ft_strlen
;		mov r9, rax
;		mov rdi, rcx ; rdi:str
;		call getsign
;		mov rdx, rax ; sign
;		; another registry required
;		loop05:
;			call get_index
;			cmp rax, -1
;			je end05
;			imul rbx, r9
;			add rbx, rax
;			jmp loop05
;		end05:
;			mov rax, rbx
;			imul rax, rdx
;			mov rdi, rcx
;			pop r9 ; < r9 < rdx < rcx < rbx
;			pop rdx ; < rdx < rcx < rbx
;			pop rcx ; < rcx < rbx
;			pop rbx ; < rbx
;			ret
