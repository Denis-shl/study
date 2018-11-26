/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:26:34 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/25 16:26:56 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		index;
	char		*point1;
	char		*point2;

	point1 = (char*) dst;
	point2 = (char*) src;
	index = 0;
	while (index != n)
	{
		*point1 = *point2;
		point1++;
		point2++;
		index++;
	}
	return (dst);
}
