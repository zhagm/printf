/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_populate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:46:01 by zmagauin          #+#    #+#             */
/*   Updated: 2019/03/07 16:56:55 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		pf_populate_flags(char *str, t_arg *arg)
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

int		pf_populate_width(char *str, t_arg *arg)
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

int		pf_populate_precision(char *str, t_arg *arg)
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
	else
		arg->precision = 0;
	return (i);
}

int		pf_populate_type(char *str, t_arg *arg)
{
	size_t	i;
	char	*num;
	char	c;

	i = 0;
	c = str[i];
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' ||
	c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
	{
		arg->type = str[i];
		i++;
	}
	else
		return (-1);
	return (i);
}
