/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:50:10 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/24 22:53:00 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int			index;
	char		*point1;
	char		*point2;

	index = 0;
	point1 = (char*) s1;
	point2 = (char*) s2;
	while (index != n && *point1 == *point2)
	{
		index++;
		point1++;
		point2++;
	}
	return (*point1 - *point2);
}
