/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:24:39 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/02/18 01:24:41 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned int nb, char *base)
{
	char	*str;
	char	*str2;	
	int		i;

	str = NULL;
	if (nb == 0)
		return (str = ft_addchar(str, base[0]));
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
