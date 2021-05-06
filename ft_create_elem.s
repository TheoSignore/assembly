section .text
	extern malloc
	global ft_create_elem

	ft_create_elem: ; rdi:data
		push rdi ; > rdi
		push rbx ; > rbx > rdi
		mov rbx, rdi ; rbx:data
		mov rdi, 16
		call malloc
		cmp rax, 0
		je end
		mov [rax], rbx
		add rax, 8
		mov qword [rax], 0
		sub rax, 8
		end:
			pop rbx ; < rbx < rdi
			pop rdi ; < rdi
			ret
