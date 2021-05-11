/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignore <tsignore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:45:11 by tsignore          #+#    #+#             */
/*   Updated: 2021/05/11 15:53:03 by tsignore         ###   ########.fr       */
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
	ft_strcpy(data, "X");
}

int cmp_example(void *a, void *b)
{
	unsigned char *c;
	unsigned char *d;
	int gneh;

	c = a;
	d = b;
	gneh = ft_strcmp(c, d);
	//printf("%p|%s\n%p|%s\n\t%i\n",a, c, b, d, gneh);
	return ();
}

void	say(char *s)
{
	write(1, s, strlen(s));
}

void	test_ftstrlen(void)
{
	printf("--- ft_strlen ---\n");
	printf("NULL - %zu %zu\n", ft_strlen(NULL), strlen(NULL));
	printf("\"\" - %zu %zu\n", ft_strlen(""), strlen(""));
	printf("\"hello world\" - %zu %zu\n", ft_strlen("hello"), strlen("world"));
	printf("\"\" - %zu %zu\n", ft_strlen("hello"), strlen("world"));
}

void	ftstrcpy(char *a, char *b, char *(*cpy)(char *, const char *))
{
	char	*res;

	printf("(\"%s\", \"%s\")\n", a, b);
	res = (cpy)(a, b);
	printf("a) %p|%s\nb) %p|%s\nr) %p|%s\n\n", a, a, b, b, res, res);
}

void	test_ftstrcpy(void)
{
	printf("--- ft_strcpy ---\n")
	char	a = "alliance";
	char	b = "assembly";
	write(1, "ft_strcpy", 9);
	ftstrcpy(a, b, &ft_strcpy);
	write(1, "strcpy", 9);
	ftstrcpy(a, b, &strcpy);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (strcmp(av[1], "ft_strlen"))
			test_ftstrlen();
		if (strcmp(av[1], "ft_strcpy"))
			test_ftstrcpy();
		if (strcmp(av[1], "ft_strcmp"))
			test_ftstrcmp();
		if (strcmp(av[1], "ft_write"))
			test_ftwrite();
		if (strcmp(av[1], "ft_read"))
			test_ftread();
		if (strcmp(av[1], "ft_atoi_base"))
			test_ftatoibase();
		if (strcmp(av[1], "ft_list"))
			test_ftlist();
		else
			printf("Unknowm argument.");
	}
}
