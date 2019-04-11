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
	int temp;
	ft_printf("|%d| should be\n|-42|<<<<<\n", -42);
	ft_printf("|%0d| should be\n|-42|<<<<<\n", -42);
	ft_printf("|%00d| should be\n|-42|<<<<<\n", -42);
// 	  97.      ft_printf("%d", 1);                           -> "1"
//   98.      ft_printf("the %d", 1);                       -> "the 1"
//   99.      ft_printf("%d is one", 1);                    -> "1 is one"
//  100. FAIL ft_printf("%d", -1);                          -> "-1"
//  101.      ft_printf("%d", 4242);                        -> "4242"
//  102. FAIL ft_printf("%d", -4242);                       -> "-4242"
//  103.      ft_printf("%d", 2147483647);                  -> "2147483647"
//  104. FAIL ft_printf("%d", 2147483648);                  -> "-2147483648"
//  105. FAIL ft_printf("%d", -2147483648);                 -> "-2147483648"
//  106.      ft_printf("%d", -2147483649);                 -> "2147483647"
//  107.      ft_printf("% d", 42);                         -> " 42"
//  108. FAIL ft_printf("% d", -42);                        -> "-42"
//  109.      ft_printf("%+d", 42);                         -> "+42"
//  110. FAIL ft_printf("%+d", -42);                        -> "-42"
//  111.      ft_printf("%+d", 0);                          -> "+0"
//  112. FAIL ft_printf("%+d", 4242424242424242424242);     -> "-1"
//  113.      ft_printf("% +d", 42);                        -> "+42"
//  114. FAIL ft_printf("% +d", -42);                       -> "-42"
//  115.      ft_printf("%+ d", 42);                        -> "+42"
//  116. FAIL ft_printf("%+ d", -42);                       -> "-42"
//  117.      ft_printf("%  +d", 42);                       -> "+42"
//  118. FAIL ft_printf("%  +d", -42);                      -> "-42"
//  119.      ft_printf("%+  d", 42);                       -> "+42"
//  120. FAIL ft_printf("%+  d", -42);                      -> "-42"
//  121.      ft_printf("% ++d", 42);                       -> "+42"
//  122. FAIL ft_printf("% ++d", -42);                      -> "-42"
//  123.      ft_printf("%++ d", 42);                       -> "+42"
//  124. FAIL ft_printf("%++ d", -42);                      -> "-42"
//  125. FAIL ft_printf("%0d", -42);                        -> "-42"
//  126. FAIL ft_printf("%00d", -42);                       -> "-42"
//  127.      ft_printf("%5d", 42);                         -> "   42"
//  128.      ft_printf("%05d", 42);                        -> "00042"
//  129. FAIL ft_printf("%0+5d", 42);                       -> "+0042"
//  130. FAIL ft_printf("%5d", -42);                        -> "  -42"
//  131. FAIL ft_printf("%05d", -42);                       -> "-0042"
//  132. FAIL ft_printf("%0+5d", -42);                      -> "-0042"
	// ft_printf("%x ---- should be", -42);
	// ft_printf("\nffffffd6\n");
	// ft_printf("%.2s is a string\n", "this");
	// ft_printf("th is a string\n");
	// ft_printf("%5.2s is a string\n", "this");
	// ft_printf("   th is a string\n");
	// ft_printf("%10s is a string\n", "");
	// ft_printf("           is a string\n");
	// ft_printf("%.2s is a string\n", "");
	// ft_printf(" is a string\n");
	// ft_printf("%5.2s is a string\n", "");
	// ft_printf("      is a string\n");
	// ft_printf("%-10s is a string\n", "this");
	// ft_printf("this       is a string\n");
	// ft_printf("%-.2s is a string\n", "this");
	// ft_printf("th is a string\n");
	// ft_printf("%-5.2s is a string\n", "this");
	// ft_printf("th    is a string\n");

	// ft_printf("|%%|\n");//                              -> "%"
	// ft_printf("|%5%|\n");//                             -> "    %"
	// ft_printf("|%-5%|\n");//                            -> "%    "
	// ft_printf("|%.0%|\n");//                            -> "%"
	// ft_printf("|%%|\n", "test");//                      -> "%"
	// ft_printf("|%   %|\n", "test");//                   -> "%"
	// ft_printf("zhag%0-8.2uan%0+dbike\n", 123, 1);
	// ft_printf("|%%|\n");
	// temp = ft_printf("|%5%|\n");
	// temp = ft_printf("|%X|", 42);
	// temp = ft_printf("|%s|\n", "abc");
	// ft_printf("|%#8x| should be \n|    0x2a|-----\n", 42);
	// ft_printf("|%#08x| should be \n|0x00002a|----\n", 42);

	// ft_printf("|%#x| (%%#x) should be \n|0|---------\n\n", 0);
	// ft_printf("|%#x| (%%#x) should be \n|0x2a|---------\n\n", 42);
	// ft_printf("|%#X| (%%#X) should be \n|0X2A|---------\n\n", 42);
	// ft_printf("|%#8x| (%%#8x) should be \n|    0x2a|---------\n\n", 42);
	// ft_printf("|%#08x| (%%#08x) should be \n|0x00002a|---------\n\n", 42);
	// ft_printf("|%#-08x| (%%#-08x) should be \n|0x2a    |---------\n\n", 42);
	// // ft_printf("neg_nums%d here and now%d", -123, -11111);
	// temp = ft_printf("This string has no args\n");
	// ft_printf("%d\n", temp);
	// printf("zhag%0-8.2uan%0+dbike\n", 123, 1);
	// printf("neg_nums%d here and now%d", -123, -11111);
	// printf("This string has no args\n");
	return (0);
}
