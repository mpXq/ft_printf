/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:36:24 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/02/17 19:53:02 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isalnum(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

size_t	ft_strlen(const char *str);

void	*ft_memset(void	*p, int v, size_t count);

void	ft_bzero(void *s, size_t n);

void	*ft_memmove(void *d, const void *s, size_t size);

void	*ft_memcpy(void *d, const void *s, size_t size);

size_t	ft_strlcpy(char *d, const char *src, size_t size);

size_t	ft_strlcat(char *d, const char *src, size_t size);

int		ft_tolower(int c);

int		ft_toupper(int c);

char	*ft_strchr(const char *str, int c);

char	*ft_strrchr(const char *str, int c);

int		ft_strncmp(const char *s1, const char *s2, size_t size);

void	*ft_memchr(const void *m, int c, size_t size);

int		ft_memcmp(const void *p1, const void *p2, size_t size);

char	*ft_strnstr(const char *s1, const char *s2, size_t size);

void	*ft_calloc(size_t c, size_t size);

int		ft_atoi(const char *str);

char	*ft_strdup(const char *s);

char	*ft_substr(const char *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strtrim(char const *s1, char const *set);

char	**ft_split(char const *s, char c);

char	*ft_itoa(int n);

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char *));

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

char	*ft_strndup(char const *line, int start, int end);

char	*ft_addchar(char const *str, char c);

char	*ft_ptoa(size_t nb);

#endif
