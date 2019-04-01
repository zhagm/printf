/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:50:04 by zmagauin          #+#    #+#             */
/*   Updated: 2019/04/01 09:39:43 by zmagauin         ###   ########.fr       */
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
	char		*str;
}				t_arg;

typedef struct	s_parser
{
	char		*type;
	int			(*parser_func)(t_arg *, va_list);
}				t_parser;

// main funcs
int		populate_arg_struct(char *str, t_arg *arg);
int		parse_print(char *str, va_list args);
int		ft_printf(char *str, ...);

// format
int		pf_format_minwidth(char **str, t_arg *arg, char *alt);

// parse
int		pf_parse_int(t_arg *arg, va_list args);
int		pf_parse_str(t_arg *arg, va_list args);
int		pf_parse_mod(t_arg *arg, va_list args);
int		pf_parser(char **str, t_arg *arg, va_list args);

// extra
int		freemulti(int count, ...);

#endif
