section .text
	global ft_strlen

	ft_strlen:
		push rdi
		mov rcx, -1
		mov rsi, rdi
		mov al, 0
		repne scasb
		sub rdi, rsi
		dec rdi
		mov rax, rdi
		pop rdi
		ret

