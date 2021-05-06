section .text
	extern free
	global ft_list_remove_if

	ft_list_remove_if: ; rdi:&e, rsi:ref, rdx:fcmp, rcx:freefct
		push rbx ; > rbx
		push r8  ; > r8 > rbx
		push r9  ; > r9 > r8 > rbx
		push r10 ; > r10 > r9 > r8 > rbx
		push r11 ; > r11 > r10 > r9 > r8 > rbx
		cmp [rdi], 0
		je end

		loop:
			mov rbx, [rdi]
			add rbx, 8
			mov r8, rbx
			sub rbx, 8
		

		end:
			pop r11 ; < r11 < r10 < r9 < r8 < rbx
			pop r10 ; < r10 < r9 < r8 < rbx
			pop r9  ; < r9 < r8 < rbx
			pop r8  ; < r8 < rbx
			pop rbx ; < rbx
			ret
