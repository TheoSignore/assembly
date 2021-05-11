section .text
	extern free
	global ft_list_remove_if

	ft_list_remove_if: ; rdi:&e, rsi:ref, rdx:fcmp, rcx:freefct
		push rbx
		push r12
		push r13
		push r14
		push r15
		push r8
		push rcx
		push rdx
		mov rbx, rdi ;rbx:&e
		mov r12, rsi ;r12:ref
		mov r13, rdx ;r13:fcmp
		mov r14, rcx ;ffree
		mov r15, rdi;r15:&e
		next:
			cmp r15, 0
			je end
			cmp qword [r15], 0
			je end
			mov rcx, [r15] ;rcx:e
			mov rdx, [r15]
			add rdx, 8 ;rdx:&(e->next)
			mov rdi, [rcx]
			mov rsi, r12
			push rcx
			push rdx
			call r13
			pop rdx
			pop rcx
			cmp rax, 0
			jne skip
			mov rdx, [rdx]
			mov rdi, [rcx]
			push rdx
			push rcx
			call r14
			pop rcx
			mov rdi, rcx
			call free
			pop rdx
			mov [r15], rdx
			jmp next
		skip:
			mov r15, rdx
			jmp next
		end:
			;mov rdi, rbx
			pop rdx
			pop rcx
			pop r8
			pop r15
			pop r14
			pop r13
			pop r12
			pop rbx
			ret
