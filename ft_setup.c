/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:32:19 by zmagauin          #+#    #+#             */
/*   Updated: 2019/03/06 16:54:40 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		populate_arg_struct(char *str, va_list args, t_arg *arg) // takes arg struct and populates it with properties presented thru str
{
	size_t	i;

	i = 0;
	printf("Before parsing |%s|\n", str);
	i += parse_flags(str + i, arg);
	printf("After flags |%s|\n", str + i);
	i += parse_width(str + i, arg);
	printf("After width |%s|, i = %zu\n", str + i, i);
	if (str[i] == '.')
	{
		i++;
		i += parse_precision(str + i, arg);
	}
	printf("After precision |%s|, i = %zu\n", str + i, i);
	i += parse_type(str + i, arg);
	printf("After type |%s|, i = %zu\n", str + i, i);
	return (i);
}

// int		print_arg(t_arg *arg, va_list args)
// {
// 	if (arg->type == c)
// 		print_char();
// 	return (0);
// }

int		parse_print(char *str, va_list args) // returns 0 if success, >0 if an error occurs
{
	size_t	start;
	size_t 	i;
	size_t	diff;
	t_arg	*curr;
	char	*res;

	curr = (t_arg *)malloc(sizeof(t_arg));
	start = 0;
	if ((i = ft_strchrindex(str, '%')) == -1)
	{
		ft_putstr(str);
		return (ft_strlen(str));
	}
	// i = 0;
	// while (str[i])
	// {
	// 	i = ft_strnchrindex(str + i, '%');
	// 	// if (str[i] == '%')
	// 	// {
	// 	// 	diff = populate_arg_struct(str + i + 1, args, curr); // returns number of chars in the %___ ie. %d returns 2, %2d returns 3
	// 	// 	if (diff > diff + 1;
	// 	// 	else 0)
	// 	// 		i +=
	// 	// 		return (-1);
	// 	// 	// print_arg(curr, args);
	// 	// }
	// 	// else
	// 	// {
	// 	// 	ft_putchar(str[i]);
	// 	// 	i++;
	// 	// }
	// }
	// ft_putstr(res);
	// free(res);
	return (i);
}
