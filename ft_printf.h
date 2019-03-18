/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:50:04 by zmagauin          #+#    #+#             */
/*   Updated: 2019/03/18 09:33:12 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/includes/libft.h"
# include <stdio.h>

typedef struct	s_arg
{
	char		*flags;
	int			min_width;
	int			precision;
	char		type;
}				t_arg;

typedef struct	s_parser
{
	char		*type;
	char		*(*parser_func)(t_arg *, va_list);
}				t_parser;

// main funcs
int		populate_arg_struct(char *str, va_list args, t_arg *arg);
int		parse_print(char *str, va_list args);
int		ft_printf(char *str, ...);

// populate
int		pf_populate_type(char *str, t_arg *arg);
int		pf_populate_precision(char *str, t_arg *arg);
int		pf_populate_width(char *str, t_arg *arg);
int		pf_populate_flags(char *str, t_arg *arg);

// format
int		pf_format_minwidth(char **str, t_arg *arg);

// parse
char	*pf_parse_int(t_arg *arg, va_list args);
int		pf_parser(char **str, t_arg *arg, va_list args);

#endif
