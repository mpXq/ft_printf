/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:54:35 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/03/06 17:45:14 by pfaria-d         ###   ########.fr       */
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

static char	*getarg(char c, va_list aptr, t_printf *p)
{
	char	*cmd;

	cmd = NULL;
	if (c == 'c')
		cmd = ft_addchar(cmd, va_arg(aptr, int), p, 0);
	else if (c == 's')
		cmd = ft_strdup2(va_arg(aptr, char *), p);
	else if (c == 'p')
	{
		cmd = ft_ptoa(va_arg(aptr, unsigned long long int), p);
		p->line += ft_strlen(cmd);
	}
	else if (c == 'd' || c == 'u')
		cmd = ft_itoa_base((int)va_arg(aptr, unsigned int), "0123456789", p);
	else if (c == 'x')
		cmd = ft_itoa_base((size_t)va_arg(aptr, size_t), "0123456789abcdef", p);
	else if (c == 'X')
		cmd = ft_itoa_base((size_t)va_arg(aptr, size_t), "0123456789ABCDEF", p);
	else if (c == '%')
		cmd = ft_addchar(cmd, '%', p, 0);
	return (cmd);
}

static void	command(t_printf *p, char *str, char *cmd)
{
	char	*tmp;

	if (ft_strlen(str) == 1)
	{
		tmp = p->line;
		p->line = ft_strjoin(tmp, cmd);
		if (ft_strlen(tmp) > 0)
			free(tmp);
		tmp = NULL;
	}
}

int	is_percentage(t_printf *p, const char *str, int i, va_list aptr)
{
	int		start;
	char	*cmd;
	char	*tmp;

	start = i;
	cmd = NULL;
	while (isflag(str[i]))
		i++;
	if (!str[i])
		return (-1);
	if (iscommand(str[i]))
		cmd = getarg(str[i++], aptr, p);
	tmp = ft_strndup(str, start, i);
	command(p, tmp, cmd);
	if (cmd)
		free(cmd);
	if (tmp)
		free(tmp);
	return (i);
}
