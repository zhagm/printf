/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:37:31 by zmagauin          #+#    #+#             */
/*   Updated: 2019/04/03 15:31:36 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_parser(char **str, t_arg *arg, va_list args)
{
	int		i;
	char	*hold;
	t_parser parse[] = {
		{ "di", &pf_parse_int },
		{ "ouxX", &pf_parse_uint },
		{ "sS", &pf_parse_str },
		{ "%%", &pf_parse_mod }
	};

	i = 0;
	while (i < 4)
	{
		if (ft_strchr(parse[i].type, arg->type))
		{
			parse[i].parser_func(arg, args);
			hold = *str;
			*str = ft_strjoin(*str, arg->str);
			// free(hold);
		}
		i++;
	}
	return (0);
}

int		pf_parse_mod(t_arg *arg, va_list args)
{
	char	*res;

	(void)args;
	res = ft_strdup("%");
	if (arg->min_width && (int)ft_strlen(res) < arg->min_width)
	{
		if (pf_format_minwidth(&res, arg, NULL) == -1)
			return (-1);
	}
	arg->str = res;
	return (1);
}

int		pf_parse_str(t_arg *arg, va_list args)
{
	char	*res;

	res = va_arg(args, char *);
	if (res == NULL)
		res = ft_strdup("(null)");
	if (arg->precision && arg->precision < (int)ft_strlen(res))
		res = ft_strsub(res, 0, (size_t)arg->precision);
	if (arg->min_width && (int)ft_strlen(res) < arg->min_width)
	{
		if (pf_format_minwidth(&res, arg, NULL) == -1)
			return (-1);
	}
	arg->str = res;
	return (1);
}

int		get_base(char type)
{
	if (type == 'x' || type == 'X')
		return (16);
	if (type == 'o' || type == 'O')
		return (8);
	return (10);
}

char	*alternate(t_arg *arg, int n)
{
	if (ft_strchr(arg->flags, '#') && n != 0)
	{
		if (arg->type == 'x' || arg->type == 'X')
			return (ft_strdup("0x"));
		if (arg->type == 'o' || arg->type == 'O')
			return (ft_strdup("0"));
	}
	return (NULL);
}

int		pf_parse_uint(t_arg *arg, va_list args)
{
	char	*res;
	char	*hold;
	int		n;
	char	*leader;

	n = va_arg(args, int);
	if ((res = ft_itoa_base(n, get_base(arg->type))) == NULL)
		return (-1);
	if (arg->flags)
	{
		leader = ft_strnew(0);
		if (ft_strchr(arg->flags, '+') && n >= 0)
			leader = ft_strdup("+");
		if (ft_strchr(arg->flags, ' ') && !(ft_strchr(arg->flags, '+')))
			leader = ft_strdup(" ");
		if (leader)
		{
			hold = res;
			res = ft_strjoin(leader, res);
			// free(hold);
			// free(leader);
		}
	}
	if (arg->min_width && (int)ft_strlen(res) < arg->min_width)
	{
		if (pf_format_minwidth(&res, arg, alternate(arg, n)) == -1)
			return (-1);
	}
	else if ((leader = alternate(arg, n)))
	{
		hold = res;
		res = ft_strjoin(leader, res);
		// free(hold);
		// free(leader);
	}
	if (arg->type == 'X' || arg->type == 'O')
	{
		n = -1;
		while (res[++n])
			if (res[n] >= 'a' && res[n] <= 'z')
				res[n] = ft_toupper(res[n]);
	}
	arg->str = res;
	return (1);
}

int		pf_parse_int(t_arg *arg, va_list args)
{
	char	*res;
	char	*hold;
	int		n;
	char	*leader;
	int		neg;

	n = va_arg(args, int);
	if (n < 0)
	{
		n *= -1;
		neg = 1;
	}
	else
		neg = 0;
	if ((res = ft_itoa_base(n, get_base(arg->type))) == NULL)
		return (-1);
	if (arg->flags || neg)
	{
		leader = ft_strnew(0);
		if ((ft_strchr(arg->flags, '+') || neg) && !ft_strchr(arg->flags, '0'))
			leader = ft_strdup(neg ? "-" : "+");
		else if (ft_strchr(arg->flags, ' ') && n > 0 && !(ft_strchr(arg->flags, '+')))
			leader = ft_strdup(" ");
		if (leader)
		{
			hold = res;
			res = ft_strjoin(leader, res);
			// free(hold);
			// free(leader);
		}
	}
	if (arg->min_width && (int)ft_strlen(res) < arg->min_width)
	{
		if ((ft_strchr(arg->flags, '+') || neg) && ft_strchr(arg->flags, '0'))
			arg->min_width--;
		if (pf_format_minwidth(&res, arg, alternate(arg, n)) == -1)
			return (-1);
		if ((ft_strchr(arg->flags, '+') || neg) && ft_strchr(arg->flags, '0'))
		{
			hold = res;
			res = ft_strjoin(neg ? "-" : "+", res);
			// free(hold);
		}
	}
	else if ((leader = alternate(arg, n)))
	{
		hold = res;
		res = ft_strjoin(leader, res);
		// free(hold);
		// free(leader);
	}
	arg->str = res;
	return (1);
}