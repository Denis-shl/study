/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:50:50 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/17 16:52:23 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		index;
	char		*point1;
	char		*point2;
	size_t		j;

	j = 0;
	point1 = (char *)dst;
	point2 = (char *)src;
	index = 0;
	if (point1 > point2)
	{
		while ((int)(--len) >= 0)
		{
			point1[len] = point2[len];
		}
	}
	else
		while (index < len)
		{
			point1[index] = point2[index];
			index++;
		}
	return (dst);
}
