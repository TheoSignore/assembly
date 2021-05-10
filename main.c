/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignore <tsignore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:45:11 by tsignore          #+#    #+#             */
/*   Updated: 2021/05/10 15:48:35 by tsignore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	printel(t_list *e)
{
	printf("%s\n", e->data);
}

void	print_list(t_list *e)
{
	t_list	*tmp;

	tmp = e;
	if (!e)
		return ;
	printel(e);
	e = e->next;
	while (e)
	{
		printel(e);
		e = e->next;
	}
	e = tmp;
}

void	free_list(t_list *e)
{
	t_list	*nxt;

	if (!e)
		return ;
	nxt = e->next;
	free(e);
	while (nxt)
	{
		e = nxt;
		nxt = e->next;
		free(e);
	}
	e = NULL;
}

int cmp_example(void *a, void *b)
{
	unsigned char *c;
	unsigned char *d;
	int gneh;

	c = a;
	d = b;
	gneh = c[0] - d[0];
	//printf("%p|%s\n%p|%s\n\t%i\n",a, c, b, d, gneh);
	return (gneh);
}

int	main(int ac, char **av)
{
	t_list	*ptr;
	int		ndx;

	ptr = NULL;
	printf("Size: %zu\n", ft_list_size(ptr));
	ft_list_push_front(&ptr, "whoop");
	ndx = 0;
	while (ndx < ac)
	{
		ft_list_push_front(&ptr, av[ndx]);
		ndx++;
	}
	printf("Size: %zu\n", ft_list_size(ptr));
	print_list(ptr);
	ft_list_sort(&ptr, &cmp_example);
	print_list(ptr);
	free_list(ptr);
	return (0);
}
