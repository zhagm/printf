/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:32:19 by zmagauin          #+#    #+#             */
/*   Updated: 2019/03/26 09:53:35 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		populate_arg_struct(char *str, va_list args, t_arg *arg)
{
	size_t	i;

	i = 0;
	(void)args;
	i += pf_populate_flags(str + i, arg);
	i += pf_populate_width(str + i, arg);
	if (str[i] == '.')
	{
		i++;
		i += pf_populate_precision(str + i, arg);
	}
	i += pf_populate_type(str + i, arg);
	return (i);
}

int		parse_print(char *str, va_list args)
{
	size_t	start;
	int		i;
	size_t	diff;
	t_arg	*curr;
	char	*res;

	if (ft_strlen(str) == 0)
		return (0);
	start = 0;
	res = ft_strnew(0);
	i = 0;
	while ((i = ft_strchrindex(str + i, '%')) != -1)
	{
		i += start;
		curr = (t_arg *)malloc(sizeof(t_arg));
		if (start < (size_t)i)
		{
			res = ft_strnjoin(res, str + start, i - start);
			start = i;
		}
		diff = populate_arg_struct(str + i + 1, args, curr);
		if (diff > 0)
			i += diff + 1;
		else
			return (-1);
		start = i;
		if ((pf_parser(&res, curr, args)) == -1)
			return (-1);
		free(curr);
	}
	if (str[start])
		res = ft_strjoin(res, str + start);
	i = ft_strlen(res);
	ft_putstr(res);
	free(res);
	return (i);
}
