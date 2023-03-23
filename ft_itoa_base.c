/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:24:39 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/03/23 20:36:29 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(int nbr, char *base, t_printf *p)
{
	char	*str;
	char	str2[10000];	
	int		i;
	long	nb;

	str = NULL;
	nb = nbr;
	if (nb == 0)
		return (str = ft_addchar(str, base[0], p, 1));
	i = 0;
	if (nb < 0)
	{
		str = ft_addchar(str, '-', p, 1);
		nb *= -1;
	}
	while (nb > 0)
	{
		str2[i++] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
	}
	while (i--)
		str = ft_addchar(str, str2[i], p, 1);
	return (str);
}

char	*ft_utoa_base(unsigned int nbr, char *base, t_printf *p)
{
	char			*str;
	char			str2[10000];	
	int				i;
	unsigned long	nb;

	str = NULL;
	nb = nbr;
	if (nb == 0)
	{
		p->len++;
		return (str = ft_addchar(str, base[0], p, 1));
	}
	i = 0;
	while (nb > 0)
	{
		str2[i++] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
	}
	p->len += i;
	while (i--)
		str = ft_addchar(str, str2[i], p, 1);
	return (str);
}
