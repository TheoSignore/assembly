section .text
	global ft_list_size

	ft_list_size: ; rdi:el
		push rdi ; > rdi
		mov rax, 0
		cmp rdi, 0
		je end
		loop:
			add rax, 1
			add rdi, 8
			mov rdi, [rdi]
			cmp rdi, 0
			jne loop
		end:
			pop rdi ; < rdi
			ret
