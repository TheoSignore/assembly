/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignore <tsignore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 22:28:57 by tsignore          #+#    #+#             */
/*   Updated: 2021/05/12 09:47:49 by tsignore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	printel(t_list *e)
{
	printf("|%p|[%p][%p]-> \"%s\"\n           [%p]\t\t-> %p\n", e, &(e->data), e->data, e->data, &(e->next), e->next);
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
}

void	print_list(t_list *e)
{
	while (e)
	{
		printel(e);
		e = e->next;
	}
}
int		free_list(t_list *e)
{
	t_list	*tmp;

	tmp = e;
	while (tmp)
	{
		e = e->next;
		free(tmp);
		tmp = e;
	}
	return (0);
}

void	ft_rem(void *data)
{
	char	*s;

	s = data;
	printf("removing: \"%s\"\n", s);
	for (size_t ndx = 0 ; s[ndx] != '\0' ; ndx++)
		s[ndx] = 'X';
	printf("------------->\t\"%s\"\n", s);
}

int		fcmp(void *a, void *b)
{
	return (ft_strcmp((char*)a, (char*)b));
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
	char	rep;
	
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
	(void)av;
	printf("--- ft_atoi_base ---\n");
	if (ac >= 3)
		printf("[%s] \"%s\" => %i\n", av[2], av[1], ft_atoi_base(av[1], av[2]));
	else
		printf("No argument supplied.\n");
	write(1, "next ? y/n: ", 12);
	ft_read(0, &rep, 1);
	if (rep != 'y')
		return (free_list(ptr));
	system("clear");
	printf("--- ft_list ---\n");
	printf("size [%p] %zu\n\n", ptr, ft_list_size(ptr));
	ft_list_push_front(&ptr, "BEGIN");
	while (strs[ndx])
	{
		ft_list_push_front(&ptr, strs[ndx]);
		ndx++;
	}
	printf("size [%p] %zu\n\n", ptr, ft_list_size(ptr));
	print_list(ptr);
	printf("-- removing the Vianneys lol --\n");
	ft_list_remove_if(&ptr, "Vianney", &fcmp, &ft_rem);
	printf("\n");
	print_list(ptr);
	ft_list_sort(&ptr, &fcmp);
	printf("-- sorted --\n");
	print_list(ptr);
}
