/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_populate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:46:01 by zmagauin          #+#    #+#             */
/*   Updated: 2019/04/02 07:32:37 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		populate_flags(char *str, t_arg *arg)
{
	size_t	i;

	i = 0;
	while (str[i] && (str[i] == '-' || str[i] == '+' || str[i] == '0' ||
	str[i] == '#' || str[i] == ' '))
		i++;
	if (i > 0)
		arg->flags = ft_strsub(str, 0, i);
	else
		arg->flags = NULL;
	return (i);
}

int		populate_width(char *str, t_arg *arg)
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
	else
		arg->min_width = 0;
	return (i);
}

int		populate_precision(char *str, t_arg *arg)
{
	size_t	i;
	char	*num;

	i = 0;
	if (str[i] != '.')
		return (i);
	i++;
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	if (i > 1)
	{
		num = ft_strsub(str, 1, i - 1);
		arg->precision = ft_atoi(num);
		free(num);
	}
	else
		arg->precision = 0;
	return (i);
}

int		populate_type(char *str, t_arg *arg)
{
	size_t	i;
	char	c;

	i = 0;
	c = str[i];
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' ||
	c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == '%')
	{
		arg->type = c;
		i++;
	}
	// add error check? if not valid type?
	return (i);
}

int		populate_arg_struct(char *str,t_arg *arg)
{
	size_t	i;

	i = 0;
	i += populate_flags(str + i, arg);
	i += populate_width(str + i, arg);
	i += populate_precision(str + i, arg);
	i += populate_type(str + i, arg);
	return (i);
}