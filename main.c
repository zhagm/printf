/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:32:19 by zmagauin          #+#    #+#             */
/*   Updated: 2019/03/06 18:19:18 by zmagauin         ###   ########.fr       */
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
	printf("\nres: %d\n", res);
	va_end(args);
	return (res);
}

int     main(void)
{
	ft_printf("zhag%3.2dan%dbike", 123, 1);
	ft_printf("This string has no args");
	return (0);
}
