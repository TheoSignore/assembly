section .text
	global ft_strcmp

	ft_strcmp:
		push rbx
		push rcx
		bgn:
			push rbx
			push rcx
			mov rax, 0
			mov rbx, 0
			mov al, [rdi]
			mov cl, [rdi]
			mov bl, [rsi]
			sub eax, ebx
			cmp cl, 0
			je end
			cmp bl, 0
			je end
			inc rdi
			inc rsi
			cmp rax, 0
			je bgn
		end:
			pop rcx
			pop rbx
			ret
