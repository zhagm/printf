/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:45:03 by zmagauin          #+#    #+#             */
/*   Updated: 2019/04/01 11:01:52 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_padding(char pad, int width)
{
	char	*res;

	if (width <= 0)
		return (NULL);
	res = ft_strnew(width);
	ft_memset(res, pad, (size_t)width);
	return (res);
}

int		pf_format_minwidth(char **str, t_arg *arg, char *alt)
{
	char	*hold;
	char	*padding;
	char	pad;

	if ((int)ft_strlen(*str) >= arg->min_width)
		return (1);
	pad = (ft_strchr(arg->flags, '0') && !(ft_strchr(arg->flags, '-'))) ? '0' : ' ';
	padding = get_padding(pad, arg->min_width - ft_strlen(*str) - (alt ? ft_strlen(alt) : 0));
	if (alt)
	{
		if (pad == '0')
		{
			hold = padding;
			padding = ft_strjoin(alt, padding);
		}
		else
		{
			hold = *str;
			*str = ft_strjoin(alt, *str);
		}
		free(alt);
		free(hold);
	}
	if (ft_strchr(arg->flags, '-'))
		*str = ft_strjoin(*str, padding);
	else
		*str = ft_strjoin(padding, *str);
	return (1);
}