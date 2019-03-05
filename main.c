/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:32:19 by zmagauin          #+#    #+#             */
/*   Updated: 2019/03/05 12:32:20 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		parse_flags(char *str, t_arg *arg)
{
	size_t	i;

	i = 0;
	while (str[i] && (str[i] == '-' || str[i] == '+' || str[i] == '0' || str[i] == '#' || str[i] == ' '))
		i++;
	if (i > 0)
		arg->flags = ft_strsub(str, 0, i);
	return (i);
}

int		parse_width(char *str, t_arg *arg)
{
	size_t	i;
	char	*num;

	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	if (i > 0)
	{
		num = ft_strsub(str, 0, i);
		arg->min_width = ft_atoi(num);
		free(num);
	}
	return (i);
}

int		parse_precision(char *str, t_arg *arg)
{
	size_t	i;
	char	*num;

	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	if (i > 0)
	{
		num = ft_strsub(str, 0, i);
		arg->precision = ft_atoi(num);
		free(num);
	}
	return (i);
}

int		is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || 
	c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X' )
		return (1);
	return (0);
}

int		parse_type(char *str, t_arg *arg)
{
	size_t	i;
	char	*num;

	i = 0;
	if (is_type(str[i]))
	{
		arg->type = str[i];
		i++;
	}
	return (i);
}

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

int		parse_print(char *str, va_list args) // returns 0 if success, >0 if an error occurs
{
	size_t 	i;
	size_t	diff;
	t_arg	*curr;

	curr = (t_arg *)malloc(sizeof(t_arg));
	i = 0;
	if (ft_strchr(str, '%') == 0)
	{
		ft_putstr(str);
		return (ft_strlen(str));
	}
	while (str[i])
	{
		if (str[i] == '%')
		{
			diff = populate_arg_struct(str + i + 1, args, curr); // returns number of chars in the %___ ie. %d returns 2, %2d returns 3
			if (diff > 0)
				i += diff + 1;
			else
				return (-1);
		}
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	return (i);
}

int		ft_printf(char *str, ...)
{
	va_list args;
	int		res;
	
	va_start(args, str);
	res = parse_print(str, args);
	va_end(args);
	return (res);
}

int     main(void)
{
	ft_printf("%-32.5d", 123);
	return (0);
}
