/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:37:31 by zmagauin          #+#    #+#             */
/*   Updated: 2019/03/18 09:33:48 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_parser(char **str, t_arg *arg, va_list args)
{

	char	*hold;
	char	*parsed;
	char	type;
	int		temp;

	t_parser (parse[1]) = {
		{ .type = "DdIi", .parser_func = &pf_parse_int }
	};

	int		i;

	i = 0;
	while (i < 1)
	{
		if (ft_strchr(parse[i].type, arg->type))
			parsed = parse[i].parser_func(arg, args);
		i++;
	}
	hold = *str;
	*str = ft_strjoin(*str, parsed);
	free(hold);
	free(parsed);
	return (0);
}

char	*pf_parse_int(t_arg *arg, va_list args)
{
	char	*res;
	char	*hold;
	int		n;

	n = va_arg(args, int);
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
	if (arg->min_width && (int)ft_strlen(res) < arg->min_width)
		if (pf_format_minwidth(&res, arg) == -1)
			return (NULL);
	return (res);
}