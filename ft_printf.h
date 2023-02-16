/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:16:05 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/02/16 21:01:25 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define TRUE 1
# define FALSE 0
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

typedef int		t_bool;

typedef struct s_printf
{
	int		len;
	char	*line;
}			t_printf;

int		ft_printf(const	char *str, ...);
#endif
