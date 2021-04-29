section .text
	global ft_strcpy

	ft_strcpy:
		push rdi
		tst:
			mov al, [rsi]
			mov [rdi], al
			inc rdi
			inc rsi
			cmp byte al, 0
			jne tst
		pop rax
		ret
