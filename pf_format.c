/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:45:03 by zmagauin          #+#    #+#             */
/*   Updated: 2019/04/01 10:17:38 by zmagauin         ###   ########.fr       */
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
// 		/*
// ft_printf("%#8x", 42);                        -> "    0x2a"
// ft_printf("%#08x", 42);                       -> "0x00002a"
// ft_printf("%#-08x", 42);                      -> "0x2a    "
// 		*/
	// diff = arg->min_width - ft_strlen(*str);
	// padding = ft_strnew(diff);
	// pad = (ft_strchr(arg->flags, '0') && !(ft_strchr(arg->flags, '-'))) ? '0' : ' ';
	// ft_memset(padding, pad, (size_t)diff);
	// if ((hold = alternate(arg, 1))) // from here down
	// {
	// 	if (pad == '0')
	// 		ft_memcpy(padding, hold, ft_strlen(hold));
	// 	else
	// 		ft_memcpy(padding + ft_strlen(padding) - ft_strlen(hold), hold, ft_strlen(hold));
	// }
	// hold = *str;
	// if (ft_strchr(arg->flags, '-') && pad == ' ')
	// 	*str = ft_strjoin(*str, padding);
	// else
	// 	*str = ft_strjoin(padding, *str);
	// freemulti(2, hold, padding); // new func
	// return (1);


	// char	*hold;
	// char	*padding;
	// int		diff;
	// char	pad;

	// if ((int)ft_strlen(*str) >= arg->min_width)
	// 	return (1);
	// diff = arg->min_width - ft_strlen(*str);
	// padding = ft_strnew(diff);
	// pad = (ft_strchr(arg->flags, '0') && !(ft_strchr(arg->flags, '-'))) ? '0' : ' ';
	// ft_memset(padding, pad, (size_t)diff);
	// if ((hold = alternate(arg))) // from here down
	// {
	// 	if (pad == '0')
	// 		ft_memcpy(padding, hold, ft_strlen(hold));
	// 	else
	// 		ft_memcpy(padding + ft_strlen(padding) - ft_strlen(hold), hold, ft_strlen(hold));
	// }
	// hold = *str;
	// if (ft_strchr(arg->flags, '-') && pad == ' ')
	// 	*str = ft_strjoin(*str, padding);
	// else
	// 	*str = ft_strjoin(padding, *str);
	// free(hold);
	// free(padding);
	// return (1);
}

// {
// 	int		len;
// 	char	*hold;
// 	char	*padding;
// 	int		diff;
// int		pf_format_minwidth(char **str, t_arg *arg, char *pre)
// 	int		zero;

// 	len = ft_strlen(*str);
// 	if (len >= arg->min_width)
// 		return (1);
// 	else if (len < arg->min_width)
// 	{
// 		diff = arg->min_width - len;
// 		hold = *str;
// 		padding = ft_strnew(diff + ft_strlen(pre));
// 		zero = (ft_strchr(arg->flags, '0') && !(ft_strchr(arg->flags, '-'))) ? 1 : 0;
// 		ft_strcat(padding, pre);
// 		ft_memset(padding + ft_strlen(pre), (zero ? '0' : ' '), (size_t)diff);
// 		if (ft_strchr(arg->flags, '-') && !zero)
// 			*str = ft_strjoin(*str, padding);
// 		else
// 			*str = ft_strjoin(padding, *str);
// 		free(hold);
// 		free(padding);
// 		return (1);
// 	}
// 	return (-1);
// }

// int		pf_format_minwidth(char **str, t_arg *arg)
// {
// 	int		len;
// 	char	*hold;
// 	char	*padding;
// 	int		diff;
// 	int		zero;

// 	len = ft_strlen(*str);
// 	if (len >= arg->min_width)
// 		return (1);
// 	else if (len < arg->min_width)
// 	{
// 		diff = arg->min_width - len;
// 		hold = *str;
// 		padding = ft_strnew(diff);
// 		zero = (ft_strchr(arg->flags, '0') && !(ft_strchr(arg->flags, '-'))) ? 1 : 0;
// 		ft_memset(padding, (zero ? '0' : ' '), (size_t)diff);
// 		if (ft_strchr(arg->flags, '-') && !zero)
// 			*str = ft_strjoin(*str, padding);
// 		else
// 			*str = ft_strjoin(padding, *str);
// 		free(hold);
// 		free(padding);
// 		return (1);
// 	}
// 	return (-1);
// }

// int		pf_format_minwidth(char **str, t_arg *arg, char *pre)
// {
// 	int		len;
// 	char	*hold;
// 	char	*padding;
// 	int		diff;
// 	int		zero;

// 	len = ft_strlen(*str);
// 	if (len >= arg->min_width)
// 		return (1);
// 	else if (len < arg->min_width)
// 	{
// 		diff = arg->min_width - len;
// 		hold = *str;
// 		padding = ft_strnew(diff + ft_strlen(pre));
// 		zero = (ft_strchr(arg->flags, '0') && !(ft_strchr(arg->flags, '-'))) ? 1 : 0;
// 		ft_strcat(padding, pre);
// 		ft_memset(padding + ft_strlen(pre), (zero ? '0' : ' '), (size_t)diff);
// 		if (ft_strchr(arg->flags, '-') && !zero)
// 			*str = ft_strjoin(*str, padding);
// 		else
// 			*str = ft_strjoin(padding, *str);
// 		free(hold);
// 		free(padding);
// 		return (1);
// 	}
// 	return (-1);
// }