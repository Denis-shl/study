/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:38:58 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/25 16:27:27 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		index;
	size_t		flag;
	char		a;
	char		*point1;
	char		*point2;

	index = 0;
	a = (char) c;
	flag = 0;
	point1 = (char*)dst;
	point2 = (char*)src;
	while (index != n)
	{
		if (*point2 == a)
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
	if (flag != 1)
		return (NULL);
	return (point1 + 1);
}
