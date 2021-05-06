section .text
	extern malloc
	global ft_create_elem

	ft_create_elem: ; rdi:data
		push rdi
		push rbx ; > rbx
		mov rbx, rdi ; rbx:data
		mov rdi, 16
		call malloc
		cmp eax, 0
		je end
		mov [rax], rbx
		add rax, 8
		mov qword [rax], 0
		sub rax, 8
		end:
			pop rbx ; < rbx
			pop rdi
			ret
