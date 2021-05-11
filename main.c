/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignore <tsignore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 22:28:57 by tsignore          #+#    #+#             */
/*   Updated: 2021/05/11 23:03:05 by tsignore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	printel(t_list *e)
{
	printf("[%p]\n[%p][%p]-> %s\n[%p]\t->%p\n", e, &(e->data), e->data, e->data, &(e->next), e->next);
}

void	print_list(t_list *e)
{
	while (e)
	{
		printel(e);
		e = e->next;
	}
}

void	ft_rem(void *data)
{
	printf("removing: [%p]\t%s\n", data, (char*)data);
	for (size_t ndx = 0 ; data[ndx] != '\0' ; ndx++)
		data[ndx] = 'X';
	printf("------------->\t%s\n", (char*)data);
}

int		main(int ac, char **av)
{
	char	*strs[11];
	char	str0[] = "Vianney";
	char	str1[] = "Mindless Self Indulgence";
	char	str2[] = "Stupeflip";
	char	str3[] = "Superorganism";
	char	str4[] = "Gorillaz";
	char	str5[] = "Magoyond";
	char	str6[] = "Vianney";
	char	str7[] = "Master Boot Record";
	char	str8[] = "Rage Against The Machine";
	char	str9[] = "Keygen Church";
	int		ndx;
	t_list	*ptr;
	strs[0] = str0;
	strs[1] = str1;
	strs[2] = str2;
	strs[3] = str3;
	strs[4] = str4;
	strs[5] = str5;
	strs[6] = str6;
	strs[7] = str7;
	strs[8] = str8;
	strs[9] = str9;
	strs[10] = NULL;
	ptr = NULL;

	ndx = 0;
	printf("size [%p] %zu\n", ptr, ft_list_size(ptr));
	ft_list_push_front(&ptr, "BEGIN");
	if (ac < 2)
	{
		while (strs[ndx])
		{
			ft_list_push_front(&ptr, strs[ndx]);
			ndx++;
		}
	}
	printf("size [%p] %zu\n", ptr, ft_list_size(ptr));
	print_list(ptr);

	t_list	*tmp;
	tmp = ptr;
	while (tmp)
	{
		ptr = ptr->next;
		free(tmp);
		tmp = ptr;
	}
}
