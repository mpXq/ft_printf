/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:16:05 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/03/06 17:29:22 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define TRUE 1
# define FALSE 0
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include "Libft/libft.h"

typedef int		t_bool;

typedef struct s_printf
{
	int		len;
	int		nlen;
	char	*line;
	t_bool	zero;
	t_bool	plus;
	t_bool	blank;
	t_bool	minus;
	t_bool	htag;
	t_bool	point;
}			t_printf;

/*-----	  MAIN	-----*/
int		ft_printf(const	char *str, ...);

/*-----	PARSING	-----*/
int		is_percentage(t_printf *p, const char *str, int i, va_list aptr);
char	*ft_addchar(char const *str, char c, t_printf *p, int pointer);
char	*ft_itoa_base(unsigned int nb, char *base, t_printf *p);
char	*ft_ptoa(unsigned long long int nb, t_printf *p);
char	*ft_strdup2(const char *s, t_printf *p);

#endif
