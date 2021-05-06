/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignore <tsignore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:45:11 by tsignore          #+#    #+#             */
/*   Updated: 2021/05/06 12:51:48 by tsignore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	main(void)
{
	char	str[] = "Dragon";
	t_list	*ptr;

	ptr = ft_create_elem(str);
	printf("%p %zu\n%p\t%s\n%p\t%p\n", ptr, sizeof(t_list), &(ptr->data), ptr->data, &(ptr->next), ptr->next);
	free(ptr);

	return (0);
}
