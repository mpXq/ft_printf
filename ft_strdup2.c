/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:27:42 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/03/06 16:43:39 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup2(const char *s, t_printf *p)
{
	void	*s2;

	if (s == NULL)
		return (ft_strdup2("(null)", p));
	if (ft_strlen(s) == 0)
		return (NULL);
	s2 = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (s2 == 0)
		return (0);
	p->len += ft_strlen(s);
	return ((char *) ft_memcpy(s2, s, ft_strlen(s) + 1));
}
