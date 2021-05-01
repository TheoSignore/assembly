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

	check_count_chrs01:
		push rbx
		push rsi
		mov rbx, rsi
		mov rsi, rdi
		mov rax, 0
		lp01:
			mov dil, [rbx]
			cmp dil, 0
			je end01
			call countchr
			cmp rax, rdx
			jg end01
			inc rbx
			jmp lp01
		end01:
			mov rdi, rsi
			pop rsi
			pop rbx
			cmp rax, rdx
			jg false01
			mov rax, 1
			ret
		false01:
			mov rax, 0
			ret

	checkbase:
		mov r8, rdi ; sav arg (base)
		call ft_strlen	; chk base
		cmp rax, 1		; sz
		jle errorbase

		mov rsi, rdi
		mov rdx, 1
		call chkcntchr

		mov rsi, badchrs
		mov rdx, 0
		call chkcntchr

		end:
			mov rdi, r8
			mov rax, 1
			ret
		errorbase:
			mov rdi, r8
			mov rax, 0
			ret

;	ft_atoi_base:
