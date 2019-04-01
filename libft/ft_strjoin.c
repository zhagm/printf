/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 08:57:18 by zmagauin          #+#    #+#             */
/*   Updated: 2019/04/01 10:51:50 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_l;
	char	*res;
	int		i;
	int		j;
	int		x;
	int		y;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	total_l = i + j;
	if ((res = (char *)malloc(total_l * sizeof(*res))) == NULL)
		return (NULL);
	x = -1;
	while (s1[++x] && x < i)
		res[x] = s1[x];
	y = 0;
	while (s2[y] && y < j)
	{
		res[x++] = s2[y++];
	}
	res[x] = '\0';
	return (res);
}
