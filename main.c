/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:32:19 by zmagauin          #+#    #+#             */
/*   Updated: 2019/03/04 15:10:29 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *str, ...)
{
	va_list curr;
	size_t i;
	char c;
	char *s;
	int d;

	va_start(curr, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == 'c')
		{
			c = va_arg(curr, int);
			ft_putchar(c);
		}
		else if (str[i] == 's')
		{
			s = va_arg(curr, char *);
			ft_putstr(s);
		}
		else if (str[i] == 'd')
		{
			d = va_arg(curr, int);
			ft_putnbr(d);
		}
		i++;
	}
	return (0);
}

int     main(void)
{
	ft_printf("%d\n", 123);
	return (0);
}
