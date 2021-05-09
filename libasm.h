/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignore <tsignore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 09:20:31 by tsignore          #+#    #+#             */
/*   Updated: 2021/05/08 13:43:47 by tsignore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBASM_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>

size_t			ft_strlen(const char *s);
char			*ft_strcpy(char *dest, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
ssize_t			ft_write(int fd, const void *buf, size_t count);
ssize_t			ft_read(int fd, void *buf, size_t count);
char			*ft_strdup(const char *s);

/*
** bonuses
*/
int				ft_atoi_base(const char *s, const char *base);

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

void			ft_list_push_front(t_list **begin, void *data);
size_t			ft_list_size(t_list *begin);

int				cmp_example(void *a, void *b);

void			ft_list_sort(t_list **begin, int (*cmp)(void*, void*));
void			ft_list_remove_if(t_list **begin, void* data_ref,
				int (*cmp)(void*, void*), void (*free_fct)(void*));

t_list			*ft_create_elem(void *data);
#endif
