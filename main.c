/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:32:19 by zmagauin          #+#    #+#             */
/*   Updated: 2019/03/07 17:01:22 by zmagauin         ###   ########.fr       */
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

int		main(void)
{
	ft_printf("zhag%0-8.2dan%0+dbike", 123, 1);
	ft_printf("neg_nums%d here and now%d", -123, -11111);
	ft_printf("This string has no args\n");
	printf("zhag%0-8.2dan%0+dbike", 123, 1);
	printf("neg_nums%d here and now%d", -123, -11111);
	printf("This string has no args\n");
	return (0);
}
