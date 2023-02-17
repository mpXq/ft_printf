/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:15:43 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/02/17 21:24:59 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ptoa(size_t nb)
{
	int		i;
	char	*base;
	char	*str;
	char	*str;

	base = "0123456789abcdef";
	str = ft_strjoin(str, "0x");
	if (nb == 0)
		return (str = ft_addchar(str, '0'));
	while (nb > 0)
	{	
		str2 = ft_addchar(str2, base[nb % ft_strlen(base)]);
		nb /= ft_strlen(base);
	}
	i = ft_strlen(str2) - 1;
	while (i)
		str = ft_addchar(str, str2[i--]);
	return (str);
}
