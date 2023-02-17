/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:54:35 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/02/17 20:06:32 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	isflag(char c)
{
	if (c == ' ' || ft_isdigit(c) || c == '+'
		|| c == '-' || c == '.' || c == '#')
		return (TRUE);
	return (FALSE);
}

static t_bool	iscommand(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (TRUE);
	return (FALSE);
}

static char	*getarg(char c, va_list aptr)
{
	char	*cmd;

	cmd = NULL;
	if (c == 'c')
		cmd = ft_addchar(cmd, va_arg(aptr, int));
	else if (c == 's')
		cmd = ft_strjoin(cmd, va_arg(aptr, char *));
	else if (c == 'p')
		cmd = ft_strjoin(cmd, ft_ptoa(va_arg(aptr, size_t)));
	return (cmd);
}

int	is_percentage(t_printf *p, const char *str, int i, va_list aptr)
{
	int		start;
	char	*cmd;

	start = i;
	cmd = NULL;
	while (isflag(str[i]))
		i++;
	if (!str[i])
		return (-1);
	if (iscommand(str[i]))
		cmd = getarg(str[i++], aptr);
//	command(p, ft_strndup(cmd, start, i));
	return (i);
}
