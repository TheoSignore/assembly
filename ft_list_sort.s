section .data
	msg db "flag", 10, 0

section .text
	extern ft_list_size
	global ft_list_sort

	flag:
		push rax
		push rdi
		push rsi
		push rdx

		mov rax, 1
		mov rdi, 1
		mov rsi, msg
		mov rdx, 5
		syscall
		pop rdx
		pop rsi
		pop rdi
		pop rax
		ret

	ft_list_sort: ; rdi:&bg, rsi:int (*cmp)(void* a, void* b)
		push rbx ; > rbx
		push rcx ; > rcx > rbx
		push rdx ; > rdx > rcx > rbx
		push r8  ; > r8 > rdx > rcx > rbx
		push r9  ; > r9 > r8 > rdx > rcx > rbx
		push r10 ; > r10 > r9 > r8 > rdx > rcx > rbx
		push r11 ; > r11 > r10 > r9 > r8 > rdx > rcx > rbx
		mov r9, rdi ; r9:&bg
		mov r10, 0 ; compteur
		mov rbx, r9 ;						rbx:&a
		mov r8, rsi ; r8:func
		mov rdi, [r9]
		call ft_list_size
		mov r11, rax
		bubble:
			add r10, 1
			mov rcx, [r9]
		loop01:
			mov rdx, rcx
			add rdx, 8
			mov rdx, [rdx]
			mov rdi, [rcx] ;rdi:a
			mov rsi, [rdx] ; rsi:b
			;push r8
			call r8




			;mov rdi, [rcx] ;rdi:a
			;mov rsi, [rdx] ; rsi:b
			;pop r8
			call r8


		end:
		mov rdi, r9
		mov rsi, r8
		pop r11 ; < r11 < r10 < r9 < rdx < rcx < rbx
		pop r10 ; < r10 < r9 < r8 < rdx < rcx < rbx
		pop r9  ; < r9 < r8 < rdx < rcx < rbx
		pop r8  ; < r8 < rdx < rcx < rbx
		pop rdx ; < rdx < rcx < rbx
		pop rcx ; < rcx < rbx
		pop rbx ; < rbx
		ret
