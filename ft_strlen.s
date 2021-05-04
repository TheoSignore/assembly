section .text
	global ft_strlen

	ft_strlen:
		push rdi
		push rsi
		push rcx
		mov rcx, -1
		mov rsi, rdi
		mov al, 0
		repne scasb
		sub rdi, rsi
		dec rdi
		mov rax, rdi
		pop rcx
		pop rsi
		pop rdi
		ret

