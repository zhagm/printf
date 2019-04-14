/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:32:19 by zmagauin          #+#    #+#             */
/*   Updated: 2019/04/03 15:19:13 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		ft_printf(char *str, ...)
{
	va_list args;
	int		res;

	va_start(args, str);
	res = parse_print(str, args);
	va_end(args);
	return (res);
}

int		main(void)
{
	ft_printf("%s", "abc");                       //-> "abc"
	// ft_printf("%s", "this is a string");          //-> "this is a string"
	// ft_printf("%s ", "this is a string");         //-> "this is a string "
	// ft_printf("%s  ", "this is a string");        //-> "this is a string  "
	// ft_printf("this is a %s", "string");          //-> "this is a string"
	// ft_printf("%s is a string", "this");          //-> "this is a string"
	// ft_printf("Line Feed %s", "\\n");             //-> "Line Feed \\n"
	// ft_printf("%10s is a string", "this");        //-> "      this is a string"
	// ft_printf("%.2s is a string", "this");        //-> "th is a string"
	// ft_printf("%5.2s is a string", "this");       //-> "   th is a string"
	// ft_printf("%10s is a string", "");            //-> "           is a string"
	// ft_printf("%.2s is a string", "");            //-> " is a string"
	// ft_printf("%5.2s is a string", "");           //-> "      is a string"
	// ft_printf("%-10s is a string", "this");       //-> "this       is a string"
	// ft_printf("%-.2s is a string", "this");       //-> "th is a string"
	// ft_printf("%-5.2s is a string", "this");      //-> "th    is a string"
	// ft_printf("%-10s is a string", "");           //-> "           is a string"
	// ft_printf("%-.2s is a string", "");           //-> " is a string"
	// ft_printf("%-5.2s is a string", "");          //-> "      is a string"
	// ft_printf("%s %s", "this", "is");             //-> "this is"
	// ft_printf("%s %s %s", "this", "is", "a");     //-> "this is a"
	// ft_printf("%s %s %s %s", "this", "is", "a", "multi"); //-> "this is a multi"
	// ft_printf("%s %s %s %s string. gg!", "this", "is", "a", "multi", "string"); //-> "this is a multi string. gg!"
	// ft_printf("%s%s%s%s%s", "this", "is", "a", "multi", "string"); //-> "thisisamultistring"
	// ft_printf("@moulitest: %s", NULL);            //-> "@moulitest: (null)"
	// ft_printf("%.2c", NULL);                      //-> "^@"
	// ft_printf("%s %s", NULL, "string");             //-> "(null) string"
  }
