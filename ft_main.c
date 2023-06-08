/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:00:58 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/06 13:22:09 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	printf("True printf\n");
	printf("%d\n", printf("{%3c}", 0));
	printf("My printf\n");
	printf("%d\n", ft_printf("{%3c}", 0));
	return (0);
}
