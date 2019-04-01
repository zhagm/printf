/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:32:19 by zmagauin          #+#    #+#             */
/*   Updated: 2019/04/01 09:52:10 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		ft_printf(char *str, ...)
{
	va_list args;
	int		res;

	va_start(args, str);
	res = parse_print(str, args);
	va_end(args);
	return (res);
}

int		freemulti(int count, ...)
{
	va_list args;
	void	*curr;

	va_start(args, count);
	while (count--)
	{
		curr = va_arg(args, void *);
		free(curr);
	}
	va_end(args);
	return (1);
}