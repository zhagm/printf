/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:45:03 by zmagauin          #+#    #+#             */
/*   Updated: 2019/03/26 10:00:44 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_format_minwidth(char **str, t_arg *arg)
{
	int		len;
	char	*hold;
	char	*padding;
	int		diff;
	int		width;

	width = arg->min_width;
	len = ft_strlen(*str);
	if (len >= width)
		return (1);
	else if (len < width)
	{
		diff = width - len;
		hold = *str;
		padding = ft_strnew(diff);
		ft_memset(padding, ' ', (size_t)diff);
		if (ft_strchr(arg->flags, '-'))
			*str = ft_strjoin(*str, padding);
		else
			*str = ft_strjoin(padding, *str);
		free(hold);
		return (1);
	}
	return (-1);
}
