/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:37:31 by zmagauin          #+#    #+#             */
/*   Updated: 2019/03/28 12:10:08 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_parser(char **str, t_arg *arg, va_list args)
{
	int		i;
	t_parser parse[] = {
		{ "DdIiouxX", &pf_parse_int },
		{ "sS", &pf_parse_str },
		{ "%%", &pf_parse_mod }
	};

	i = 0;
	while (i < 3)
	{
		if (ft_strchr(parse[i].type, arg->type))
		{
			parse[i].parser_func(arg, args, str);
		}
		i++;
	}
	return (0);
}

int		pf_parse_mod(t_arg *arg, va_list args, char **str)
{
	char	*res;
	char	*hold;

	(void)args;
	res = ft_strnew(1);
	res[0] = '%';
	if (arg->min_width && (int)ft_strlen(res) < arg->min_width)
	{
		if (pf_format_minwidth(&res, arg) == -1)
			return (-1);
	}
	hold = *str;
	*str = ft_strjoin(*str, res);
	free(hold);
	free(res);
	return (1);
}

int		pf_parse_str(t_arg *arg, va_list args, char **str)
{
	char	*res;
	char	*hold;

	res = va_arg(args, char *);
	if (res == NULL)
		res = "(null)";
	if (arg->min_width && (int)ft_strlen(res) < arg->min_width)
	{
		if (pf_format_minwidth(&res, arg) == -1)
			return (-1);
	}
	hold = *str;
	*str = ft_strjoin(*str, res);
	// free(hold);
	// free(res);
	return (1);
}

int		pf_parse_int(t_arg *arg, va_list args, char **str)
{
	char	*res;
	char	*hold;
	int		n;
	int		base;
	char	*leader;

	n = va_arg(args, int);
	base = 10;
	if (ft_strchr("xX", arg->type))
		base = 16;
	else if (ft_strchr("oO", arg->type))
		base = 8;
	res = ft_itoa_base(n, base);
	if (res == NULL)
		return (-1);
	if (arg->flags)
	{
		leader = NULL;
		if (ft_strchr(arg->flags, '+') && n >= 0)
			leader = ft_strdup("+");
		else if (ft_strchr(arg->flags, ' '))
			leader = ft_strdup(" ");
		else if (ft_strchr(arg->flags, '0') && !(ft_strchr(arg->flags, '-')))
			leader = ft_strdup("0");
		if (leader)
		{
			hold = *str;
			*str = ft_strjoin(leader, *str);
			free(hold);
			free(leader);
		}
	}
	if (arg->min_width && (int)ft_strlen(res) < arg->min_width)
	{
		if (pf_format_minwidth(&res, arg) == -1)
			return (-1);
	}
	hold = *str;
	if (arg->type == 'X' || arg->type == 'O')
	{
		n = 0;
		while (res[n])
		{
			if (res[n] >= 65 && res[n] <= 90)
				res[n] = ft_toupper(res[n]);
			n++;
		}
	}
	*str = ft_strjoin(*str, res);
	free(hold);
	free(res);
	return (1);
}