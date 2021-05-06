section .text
	extern ft_create_elem
	global ft_list_push_front

	ft_list_push_front: ; rdi:&bgn, rsi:data
		push rbx ; > rbx
		push rcx ; > rcx > rbx
		cmp rdi, 0
		je end
		mov rbx, rdi ; rbx:&bgn
		mov rdi, rsi ; rdi:data
		call ft_create_elem
		cmp rax, 0
		je end
		add rax, 8
		mov rcx, [rbx]
		mov qword [rax], rcx
		sub rax, 8
		mov [rbx], rax
		end:
			pop rcx ; < rcx < rbx
			pop rbx ; < rbx
			ret
