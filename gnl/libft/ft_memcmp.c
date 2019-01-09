/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:50:10 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/17 16:51:44 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				index;
	unsigned char		*point1;
	unsigned char		*point2;

	index = 0;
	point1 = (unsigned char *)s1;
	point2 = (unsigned char *)s2;
	while (index != n && point1[index] == point2[index])
	{
		index++;
	}
	if (index == n)
		return (0);
	return ((unsigned char)point1[index] - (unsigned char)point2[index]);
}
