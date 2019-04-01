/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:32:19 by zmagauin          #+#    #+#             */
/*   Updated: 2019/04/01 10:12:47 by zmagauin         ###   ########.fr       */
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



	ft_printf("%32s", "abc");
	// ft_printf("zhag%0-8.2uan%0+dbike\n", 123, 1);
	// ft_printf("|%%|\n");
	// temp = ft_printf("|%5%|\n");
	// temp = ft_printf("|%X|", 42);
	// temp = ft_printf("|%s|\n", "abc");
	// ft_printf("|%#8x| should be \n|    0x2a|-----\n", 42);
	// ft_printf("|%#08x| should be \n|0x00002a|----\n", 42);

	// ft_printf("|%#x| (%%#x) should be \n|0|---------\n\n", 0);
	// ft_printf("|%#x| (%%#x) should be \n|0x2a|---------\n\n", 42);
	// ft_printf("|%#X| (%%#X) should be \n|0X2A|---------\n\n", 42);
	// ft_printf("|%#8x| (%%#8x) should be \n|    0x2a|---------\n\n", 42);
	// ft_printf("|%#08x| (%%#08x) should be \n|0x00002a|---------\n\n", 42);
	// ft_printf("|%#-08x| (%%#-08x) should be \n|0x2a    |---------\n\n", 42);
	// // ft_printf("neg_nums%d here and now%d", -123, -11111);
	// temp = ft_printf("This string has no args\n");
	// ft_printf("%d\n", temp);
	// printf("zhag%0-8.2uan%0+dbike\n", 123, 1);
	// printf("neg_nums%d here and now%d", -123, -11111);
	// printf("This string has no args\n");
	return (0);
}
