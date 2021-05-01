/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignore <tsignore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:45:11 by tsignore          #+#    #+#             */
/*   Updated: 2021/05/01 17:12:16 by tio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

int		ft_atoi_base(const char *s, const char *base);
size_t	countchr(char c, char *s);
size_t	checkbase(char *base);

void	ft_list_push_front(t_list **el, t_list *nw_el);
size_t	ft_list_size(t_list **el);
t_list	*ft_list_sort(t_list **el);
void	*ft_list_remove_if(t_list **el, int (*f)(void*));

int	main(int ac, char **av)
{
	int		fd;
	char	str[] = "Without just one nest\nA bird can call the world his home\nLife is your carrier";
	(void)ac;
	(void)av;

	ft_write(1, "\nft_strlen\n\n", 13);// ft_strlen

	printf("1>%s\t[%zu]\n", "", ft_strlen(""));
	printf("2>%s\t[%zu]\n", "", strlen(""));
	printf("1>%s\t[%zu]\n", str, ft_strlen(str));
	printf("2>%s\t[%zu]\n", str, strlen(str));

	ft_write(1, "\nft_strcpy\n\n", 13);// ft_strcpy

	char	src[] = "WH4T N0W ?!";
	char	*dst;

	dst = malloc(ft_strlen(src) + 1);
	dst = ft_strcpy(dst, src);
	ft_strcpy(src, ":o)");
	printf("src: %s\ndst: %s\n", src, dst);

	ft_write(1, "\nft_strcmp\n\n", 13);// ft_strcmp

	ft_strcpy(src, dst);
	printf("1> '%s' '%s' [%i]\n", src, dst, ft_strcmp(src, dst));
	printf("2> '%s' '%s' [%i]\n", src, dst, strcmp(src, dst));
	printf("1> '%s' '%s' [%i]\n", src, "", ft_strcmp(src, ""));
	printf("2> '%s' '%s' [%i]\n", src, "", strcmp(src, ""));
	printf("1> '%s' '%s' [%i]\n", "", dst, ft_strcmp("", dst));
	printf("2> '%s' '%s' [%i]\n", "", dst, strcmp("", dst));
	printf("1> '%s' '%s' [%i]\n", "", "", ft_strcmp("", ""));
	printf("2> '%s' '%s' [%i]\n", "", "", strcmp("", ""));
	ft_strcpy(src, "WHAT");
	printf("1> '%s' '%s' [%i]\n", src, dst, ft_strcmp(src, dst));
	printf("2> '%s' '%s' [%i]\n", src, dst, strcmp(src, dst));
	ft_strcpy(dst, "Brocoli");
	printf("1> '%s' '%s' [%i]\n", src, dst, ft_strcmp(src, dst));
	printf("2> '%s' '%s' [%i]\n", src, dst, strcmp(src, dst));


	ft_write(1, "\nft_write\n\n", 11);//ft_write


	errno = 0; fd = 1;
	printf("1>[%zi](%i)\n", ft_write(fd, "", 1), errno);
	errno = 0;
	printf("2>[%zi](%i)\n", write(fd, "", 1), errno);

	errno = 0; fd = 0; char str2[] = "Singularity ";
	printf("1>[%zi](%i)\n", ft_write(fd, str2, ft_strlen(str2)), errno);
	errno = 0;
	printf("2>[%zi](%i)\n", write(fd, str2, ft_strlen(str2)), errno);
	
	errno = 0; fd = 12;
	printf("1>[%zi](%i)\n", ft_write(fd, str2, ft_strlen(str2)), errno);
	errno = 0;
	printf("2>[%zi](%i)\n", write(fd, str2, ft_strlen(str2)), errno);

	errno = 0; fd = -1;
	printf("1>[%zi](%i)\n", ft_write(fd, str2, ft_strlen(str2)), errno);
	errno = 0;
	printf("2>[%zi](%i)\n", write(fd, str2, ft_strlen(str2)), errno);

	errno = 0; fd = 1;
	printf("1>[%zi](%i)\n", ft_write(fd, str2, ft_strlen(str2)), errno);
	errno = 0;
	printf("2>[%zi](%i)\n", write(fd, str2, ft_strlen(str2)), errno);

/*
	ft_write(1, "\nft_read\n\n", 11);//ft_read


	errno = 0; fd = 0; char str3[30];
	printf("1>[%zi](%i)\n", ft_read(fd, str3, 11), errno);
	errno = 0;
	printf("2>[%zi](%i)\n", read(fd, str3, 11), errno);
	
	errno = 0; fd = 12;
	printf("1>[%zi](%i)\n", ft_read(fd, str3, 7), errno);
	errno = 0;
	printf("2>[%zi](%i)\n", read(fd, str3, 7), errno);

	errno = 0; fd = open("Makefile", O_RDONLY);
	printf("1>[%zi](%i)", ft_read(fd, str3, 21), errno);
	ft_write(1, str3, 21);
	ft_write(1, "\n", 1);
	errno = 0;
	ft_strcpy(str3, "");
	printf("2>[%zi](%i)", read(fd, str3, 21), errno);
	ft_write(1, str3, 21);
	ft_write(1, "\n", 1);
*/
	char *dup = ft_strdup("testing");
	printf("\n%s\n", dup);
	free(dup);
	//ft_write(1, dup, 8);
	//ft_write(1, "\n", 1);

	if (ac == 2)
	printf("\n[%zu] %s\n", checkbase(av[1]), av[1]);

	return (0);
}
