section .text
	extern malloc
	extern ft_strcpy
	extern ft_strlen
	global ft_strdup

	ft_strdup:
		call ft_strlen
		add rax, 1
		mov rbx, rdi
		mov rdi, rax
		call malloc
		mov rdi, rax
		mov rsi, rbx
		call ft_strcpy
		ret
