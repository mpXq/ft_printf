/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:22:23 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/03/23 19:32:49 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_addchar(char const *str, char c, t_printf *p, int pointer)
{
	char	*str2;
	int		i;

	if (p->line && !p->line[p->len - 1] && !pointer)
	{
		p->len++;
		return ((char *)str);
	}
	if (!pointer)
		p->len++;
	i = -1;
	str2 = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (ft_strlen(str) == 0)
		i = 0;
	while (str && str[++i])
		str2[i] = str[i];
	str2[i++] = c;
	str2[i] = 0;
	if (ft_strlen(str) > 0)
		free((char *)str);
	str = NULL;
	return (str2);
}
