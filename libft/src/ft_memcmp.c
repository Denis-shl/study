/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:50:10 by oargrave          #+#    #+#             */
/*   Updated: 2019/08/05 15:56:08 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
