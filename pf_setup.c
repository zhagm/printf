/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:32:19 by zmagauin          #+#    #+#             */
/*   Updated: 2019/03/07 17:22:42 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		populate_arg_struct(char *str, va_list args, t_arg *arg) // takes arg struct and populates it with properties presented thru str
{
	size_t	i;

	i = 0;
	// printf("Before parsing |%s|\n", str);
	i += pf_populate_flags(str + i, arg);
	// printf("After flags |%s|\n", str + i);
	i += pf_populate_width(str + i, arg);
	// printf("After width |%s|, i = %zu\n", str + i, i);
	if (str[i] == '.')
	{
		i++;
		i += pf_populate_precision(str + i, arg);
	}
	// printf("After precision |%s|, i = %zu\n", str + i, i);
	i += pf_populate_type(str + i, arg);
	// printf("After type |%s|, i = %zu\n", str + i, i);
	// printf("i = %zu", i);
	return (i);
}

int		pf_parser(char **str, t_arg *arg, va_list args) // creates string from t_arg, concats to str
{
	char	*hold;
	char	*parsed;
	char	type;
	int		temp;

	type = arg->type;
	if (type == 'd')
	{
		temp = va_arg(args, int);
		parsed = pf_parse_int(temp, arg);
	}
	hold = *str;
	if (parsed)
		*str = ft_strjoin(*str, parsed);
	free(hold);
	return (1);
}

int		parse_print(char *str, va_list args) // returns 0 if success, >0 if an error occurs
{
	size_t	start;
	int		i;
	size_t	diff;
	t_arg	*curr;
	char	*res;

	start = 0;
	res = ft_strnew(0);
	i = 0;
	while ((i = ft_strchrindex(str + i, '%')) != -1)
	{
		i += start;
		curr = (t_arg *)malloc(sizeof(t_arg));
		if (start < i)
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
	{
		res = ft_strjoin(res, str + start);
		i = ft_strlen(res);
	}
	ft_putstr(res);
	free(res);
	return (i);
}
