/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:29:18 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/04/17 15:08:52 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initializer(t_printf *p)
{
	p->lostlen = 0;
	p->len = 0;
	p->nlen = 0;
	p->line = 0;
	p->zero = FALSE;
	p->space = FALSE;
	p->htag = FALSE;
	p->minus = FALSE;
	p->plus = FALSE;
	p->prec = 0;
}

int	ft_printf(const	char *str, ...)
{
	t_printf	p;
	int			i;
	va_list		aptr;

	va_start(aptr, str);
	if (!str)
		return (0);
	initializer(&p);
	i = 0;
	while (str && str[i])
	{
		if (str[i] == '%' && i++ > -1)
			i = is_percentage(&p, str, i, aptr);
		else
			p.line = ft_addchar(p.line, str[i++], &p, 0);
		if (i == -1)
			break ;
	}
	ft_putstr_fd(p.line, 1);
	if (ft_strlen(p.line) > 0)
		free(p.line);
	p.len += p.lostlen;
	return (p.len);
}
