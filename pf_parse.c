/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:37:31 by zmagauin          #+#    #+#             */
/*   Updated: 2019/03/07 17:21:29 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_parse_int(int n, t_arg *arg)
{
	char	*res;
	char	*hold;

	res = ft_itoa(n);
	if (res == NULL)
		return (NULL);
	if (arg->flags)
	{
		if (ft_strchr(arg->flags, '+') && n >= 0)
		{
			hold = res;
			res = ft_strjoin("+", res);
			free(hold);
		}
		else if (ft_strchr(arg->flags, ' '))
		{
			hold = res;
			res = ft_strjoin(" ", res);
			free(hold);
		}
		else if (ft_strchr(arg->flags, '0') && !(ft_strchr(arg->flags, '-')))
		{
			hold = res;
			res = ft_strjoin("0", res);
			free(hold);
		}
	}
	if (arg->min_width && ft_strlen(res) < arg->min_width)
		if (pf_format_minwidth(&res, arg) == -1)
			return (NULL);
	return (res);
}
