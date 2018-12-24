/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:38:58 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/24 20:06:39 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		index;
	char		*point1;
	char		*point2;
	int			flag;

	flag = 0;
	index = 0;
	point1 = (char *)dst;
	point2 = (char *)src;
	while (index != n)
	{
		if (*point2 == (char)c)
		{
			*point1 = *point2;
			flag = 1;
			break ;
		}
		*point1 = *point2;
		index++;
		point1++;
		point2++;
	}
	if (flag == 1)
		return (point1 + 1);
	return (NULL);
}
