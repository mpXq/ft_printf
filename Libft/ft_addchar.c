/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:22:23 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/02/18 01:09:27 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addchar(char const *str, char c)
{
	char	*str2;
	int		i;

	i = -1;
	str2 = malloc((ft_strlen(str) * sizeof(char)) + 2);
	if (ft_strlen(str) == 0)
		i = 0;
	while (str && str[++i])
		str2[i] = str[i];
	if (!c)
		str2 = ft_strjoin(str2, "(null)");
	else
	{
		str2[i++] = c;
		str2[i] = 0;
	}
	return (str2);
}
