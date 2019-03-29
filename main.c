/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:32:19 by zmagauin          #+#    #+#             */
/*   Updated: 2019/03/28 11:18:52 by zmagauin         ###   ########.fr       */
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
	int temp;

	// ft_printf("zhag%0-8.2uan%0+dbike\n", 123, 1);
	temp = ft_printf("%5%");
	ft_printf("%d\n", temp);
	temp = ft_printf("%X", 42);
	ft_printf("%d\n", temp);
	temp = ft_printf("%s\n", "abc");
	ft_printf("%d\n", temp);
	// ft_printf("neg_nums%d here and now%d", -123, -11111);
	temp = ft_printf("This string has no args\n");
	ft_printf("%d\n", temp);
	// printf("zhag%0-8.2uan%0+dbike\n", 123, 1);
	// printf("neg_nums%d here and now%d", -123, -11111);
	// printf("This string has no args\n");
	return (0);
}
