section .data
	msg db "flag", 10, 0

section .text
	extern ft_list_size
	global ft_list_sort

	ft_list_sort: ; rdi:&bg, rsi:int (*cmp)(void* a, void* b)
		; rsp, rbp, rbx, r12, r13, r14, r15
		; bubble sort
		push rbx
		push r12
		push r13
		push r14
		push r15
		push rcx
		push rdx
		push r8
		mov rbx, rdi ; rbx:bg
		mov r12, rsi ; rsi:func
		mov rdi, [rdi] ; rdi:bg
		call ft_list_size
		mov r13, rax ; r13:size
		mov r14, 0 ; r14:count
		bubble:
			mov r15, [rbx]
		loop00:
			mov rdi, [r15]
			add r15, 8
			cmp qword [r15], 0
			je next
			mov rcx, r15
			sub rcx, 8
			push rcx
			mov r15, [r15]
			mov rsi, [r15]
			call r12
			pop rcx
			cmp eax, 0
			jle loop00
			;swap data
			mov rdx, [r15]
			mov r8, [rcx]
			mov [rcx], rdx
			mov [r15], r8
			jmp loop00
		next:
			inc r14
			cmp r14, r13
			jle bubble
		end:
			mov rdi, rbx
			pop r8
			pop rdx
			pop rcx
			pop r15
			pop r14
			pop r13
			pop r12
			pop rbx
		ret
