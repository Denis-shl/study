/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:50:50 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/24 23:13:13 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int			index;
	char		*str;
	char		*point1;
	char		*point2;

	point1 = (char*) dst;
	point2 = (char*) src;
	index = 0;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	while (index != len)
	{
		str[index] = point2[index];
		index++;
	}
	str[index] = '\0';
	index = 0;
	while (str[index] != '\0')
	{
		point1[index] = str[index];
		index++;
	}
	return (dst);
}
