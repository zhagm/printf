/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:46:01 by zmagauin          #+#    #+#             */
/*   Updated: 2019/03/05 12:49:21 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		parse_flags(char *str, t_arg *arg)
{
	size_t	i;

	i = 0;
	while (str[i] && (str[i] == '-' || str[i] == '+' || str[i] == '0' || 
	str[i] == '#' || str[i] == ' '))
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
