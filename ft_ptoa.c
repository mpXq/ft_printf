/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:15:43 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/03/01 15:41:24 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ptoa(size_t nb, t_printf *p)
{
	int		i;
	char	*base;
	char	*str;
	char	*str2;

	str = NULL;
	base = "0123456789abcdef";
	str = ft_strjoin(str, "0x");
	if (nb == 0)
		return (str = ft_addchar(str, '0', p));
	while (nb > 0)
	{	
		str2 = ft_addchar(str2, base[nb % ft_strlen(base)], p);
		nb /= ft_strlen(base);
	}
	i = ft_strlen(str2) - 1;
	while (i)
		str = ft_addchar(str, str2[i--], p);
	return (str);
}
