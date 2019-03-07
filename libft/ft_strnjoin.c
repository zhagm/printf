/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <zmagauin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 08:57:18 by zmagauin          #+#    #+#             */
/*   Updated: 2019/03/06 18:47:39 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*res;
	int		i;
	int		j;
	size_t	temp;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		i++;
	temp = 0;
	while (s2[j] && temp++ < n)
		j++;
	if ((res = (char *)malloc((i + j) * sizeof(*res))) == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = 0;
	temp = 0;
	while (s2[j] && temp++ < n)
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
