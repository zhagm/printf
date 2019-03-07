/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrindex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 07:36:10 by zmagauin          #+#    #+#             */
/*   Updated: 2019/03/06 16:16:36 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchrindex(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		else
			i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}
