/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:15:43 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/03/06 17:43:14 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ptoa(unsigned long long int nb, t_printf *p)
{
	int		i;
	char	*base;
	char	*str;
	char	*str2;

	str = NULL;
	str2 = NULL;
	base = "0123456789abcdef";
	str = ft_strjoin(str, "0x");
	if (nb == 0)
		return (str = ft_addchar(str, '0', p, 1));
	while (nb > 0)
	{	
		str2 = ft_addchar(str2, base[nb % 16], p, 1);
		nb /= 16;
	}
	i = ft_strlen(str2);
	while (i)
		str = ft_addchar(str, str2[--i], p, 1);
	p->line += ft_strlen(str);
	//free(str2);
	return (str);
}
