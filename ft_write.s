section .text
	extern __errno_location
	global ft_write

	ft_write:
		push rbx
		mov rax, 1
		syscall
		cmp rax, 0
		jge end
		mov rbx, rax
		call __errno_location
		neg rbx
		mov [rax], rbx
		mov rax, -1
	end:
		pop rbx
		ret
