/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignore <tsignore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:45:11 by tsignore          #+#    #+#             */
/*   Updated: 2021/05/11 11:59:10 by tsignore         ###   ########.fr       */
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

void	free_list(t_list **e)
{
	t_list	*tmp;
	t_list	*nxt;

	if (!e)
		return ;
	tmp = e[0];
	nxt = tmp->next;
	free(tmp);
	while (nxt)
	{
		tmp = nxt;
		nxt = tmp->next;
		free(tmp);
	}
	tmp = NULL;
}

void ft_rem(void *data)
{
	printf("%p|%s\n", data, (char *)data);
	data = NULL;
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
	ft_list_push_front(&ptr, "beg");
	ndx = 0;
	while (ndx < ac)
	{
		ft_list_push_front(&ptr, av[ndx]);
		ndx++;
	}
	printf("Size: %zu\n", ft_list_size(ptr));
	print_list(ptr);
	write(1, "\n", 1);
	ft_list_remove_if(&ptr, "j", &cmp_example, ft_rem);
	write(1, "\n", 1);
	print_list(ptr);
	free_list(&ptr);
	return (0);
}
