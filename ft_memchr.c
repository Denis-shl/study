/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:31:25 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/17 16:43:41 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	char			a;
	char			*point;

	index = 0;
	a = (char)c;
	point = (char *)s;
	while (index != n)
	{
		if (*point == a)
			return (point);
		index++;
		point++;
	}
	return (NULL);
}
