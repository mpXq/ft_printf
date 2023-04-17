/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:54:35 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/04/17 15:07:35 by pfaria-d         ###   ########.fr       */
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
		cmd = ft_ptoa(va_arg(aptr, unsigned long long int), p);
	else if (c == 'd' || c == 'i')
	{
		cmd = ft_itoa_base((int)va_arg(aptr, int), "0123456789", p);
		p->len += ft_strlen(cmd);
	}
	else if (c == 'u')
		cmd = ft_utoa_base((int)va_arg(aptr, unsigned int), "0123456789", p);
	else if (c == 'x')
		cmd = ft_utoa_base((size_t)va_arg(aptr, size_t), "0123456789abcdef", p);
	else if (c == 'X')
		cmd = ft_utoa_base((size_t)va_arg(aptr, size_t), "0123456789ABCDEF", p);
	else if (c == '%')
		cmd = ft_addchar(cmd, '%', p, 0);
	return (cmd);
}

int	changelen(char *str, int i, t_printf *p)
{
	int		start;
	char	*tmp;

	start = i;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	tmp = ft_strndup(str, start, i);
	p->nlen = ft_atoi(tmp);
	free(tmp);
	return (i - start);
}

int	changeprec(char *str, int i, t_printf *p)
{
	int		start;
	char	*tmp;

	start = i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	tmp = ft_strndup(str, start + 1, i);
	p->prec = ft_atoi(tmp);
	if (start + 1 == i)
		p->prec = -1;
	free(tmp);
	return (i - start);
}

void	flags(t_printf *p, char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		if (str[i] == '+' && i++ > -1)
			p->plus = TRUE;
		if (str[i] == '-' && i++ > -1)
			p->minus = TRUE;
		if (str[i] == ' ' && i++ > -1)
			p->space = TRUE;
		if (str[i] == '#' && i++ > -1)
			p->htag = TRUE;
		if (str[i] == '0' && i++ > -1)
			p->zero = TRUE;
		if (str[i] == '.')
			i += changeprec(str, i, p);
		if (ft_isdigit(str[i]) && str[i] != '0')
			i += changelen(str, i, p); 
	}
}

char	*createwidth(t_printf *p, char *bcmd)
{
	char	*tmp;
	int		i;
	int		x;

	i = p->nlen - (int)ft_strlen(bcmd);
	if (ft_strlen(bcmd) > 0 && p->zero == TRUE && !ft_strncmp(bcmd, "-", 1))
		i++;
	tmp = malloc(sizeof(char) * (i + 1));
	x = 0;
	if (ft_strlen(bcmd) > 0 && p->zero == TRUE && !ft_strncmp(bcmd, "-", 1))
		tmp[x++] = '-';
	while (x < i)
	{
		if (p->zero == TRUE)
			tmp[x] = '0';
		else
			tmp[x] = ' ';
		x++;
	}
	tmp[x] = 0;
	return (tmp);
}

char	*createwidth2(char *bcmd, int i)
{
	char	*tmp;
	int		x;

	if (ft_strlen(bcmd) > 0 && !ft_strncmp(bcmd, "-", 1))
		i++;
	tmp = malloc(sizeof(char) * (i + 1));
	x = 0;
	if (ft_strlen(bcmd) > 0 && !ft_strncmp(bcmd, "-", 1))
		tmp[x++] = '-';
	while (x < i)
	{
		tmp[x] = '0';
		x++;
	}
	tmp[x] = 0;
	return (tmp);
}

void	reinitializer(t_printf *p)
{
	p->nlen = 0;
	p->zero = FALSE;
	p->plus = FALSE;
	p->minus = FALSE;
	p->space = FALSE;
	p->htag = FALSE;
	p->prec = 0;
}

char	*flag_gestion(t_printf *p, char *cmd, char c)
{
	char	*bcmd;
	char	*tmp;
	int		len;
	int		len2;
	int		x;

	bcmd = cmd;
	x = 0;
	if (p->prec != 0 && cmd)
	{
		x++;
		if (p->prec < (int)ft_strlen(cmd) && c == 's')
			cmd = ft_strndup(cmd, 0, p->prec); 
		else if ((p->prec > (int)ft_strlen(cmd) || (p->prec >= (int)ft_strlen(cmd) && !ft_strncmp("-", bcmd, 1))) && (c == 'd' || c == 'i' || c == 'u' || c == 'X' || c == 'x'))
		{
			char	*tmp2;

			if (bcmd && !ft_strncmp(bcmd, "-", 1))
				tmp = createwidth2(bcmd, p->prec - (int)ft_strlen(bcmd) + 1); 
			else
				tmp = createwidth2(bcmd, p->prec - (int)ft_strlen(bcmd)); 
			tmp2 = cmd;
			if (bcmd && !ft_strncmp(bcmd, "-", 1))
				tmp2 = ft_strndup(cmd, 1, ft_strlen(cmd));
			cmd = ft_strjoin(tmp, tmp2);
			if (bcmd && !ft_strncmp(bcmd, "-", 1))
				free(tmp2);
			free(tmp);
		}
	}
	if (p->line && (!p->line[p->len - 1 - (ft_strlen(bcmd))]))
	{
		if (p->nlen > 1)
			p->lostlen += p->nlen - 1;
		return (0);
	}
	if (x)
		p->len -= (ft_strlen(bcmd) - ft_strlen(cmd));
	len = ft_strlen(cmd);
	if ((c == 'd' || c == 'i') && p->plus == TRUE && ft_atoi(bcmd) >= 0)
		cmd = ft_strjoin("+", cmd);
	else if (c == 'x' && p->htag == TRUE && ft_strncmp(bcmd, "0", 2))
		cmd = ft_strjoin("0x", cmd);
	else if (c == 'X' && p->htag == TRUE && ft_strncmp(bcmd, "0", 2))
		cmd = ft_strjoin("0X", cmd);
	else if ((c == 'd' || c == 'i') && p->space == TRUE && ft_atoi(bcmd) >= 0)
		cmd = ft_strjoin(" ", cmd);
	if (p->nlen > 0 && p->nlen > (int)ft_strlen(bcmd))
	{
		tmp = createwidth(p, bcmd);
		if (p->minus == TRUE)
			cmd = ft_strjoin(cmd, tmp);
		else
		{
			char	*tmp2;

			tmp2 = cmd;
			if (bcmd && !ft_strncmp(bcmd, "-", 1))
				tmp2 = ft_strndup(cmd, 1, ft_strlen(cmd));
			cmd = ft_strjoin(tmp, tmp2);
			if (bcmd && !ft_strncmp(bcmd, "-", 1))
				free(tmp2);
		}
		free(tmp);
	}
	len2 = ft_strlen(cmd);
	p->len += len2 - len;
	return (cmd);
}

static void	command(t_printf *p, char *str, char *cmd, char c)
{
	char	*tmp;
	char	*tmp2;

	if (ft_strlen(str) == 1)
	{
		tmp = p->line;
		p->line = ft_strjoin(tmp, cmd);
		if (ft_strlen(tmp) > 0)
			free(tmp);
		tmp = NULL;
	}
	else if (iscommand(c))
	{
		tmp2 = cmd;
		flags(p, str, c);
		if (ft_strlen(cmd) == 0 && p->prec != 0)
			p->prec = -1;
		if (p->prec == -1)
		{
			p->len -= ft_strlen(cmd);
			reinitializer(p);
			return ;
		}
		tmp = p->line;
		cmd = flag_gestion(p, cmd, c);
		p->line = ft_strjoin(tmp, cmd);
		free(tmp);
		tmp = NULL;
		if (((tmp2 && cmd && ft_strncmp(tmp2, cmd, 10000)) || !tmp2))
			free(cmd);
		cmd = NULL;
	}
	reinitializer(p);
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
	command(p, tmp, cmd, str[--i]);
	i++;
	if (cmd)
		free(cmd);
	if (tmp)
		free(tmp);
	return (i);
}
