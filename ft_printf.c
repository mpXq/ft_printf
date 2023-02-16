/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:29:18 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/02/16 21:46:52 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initializer(t_printf	*p)
{
	p->len = 0;
	p->line = 0;
}

int	ft_printf(const	char *str, ...)
{
	t_printf	p;

	(void)str;
	initializer(&p);
	return (p.len);
}
