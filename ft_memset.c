/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:59:42 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/17 16:52:00 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	char			a;
	char			*point;

	point = (char *)b;
	a = c;
	i = 0;
	while (i != n)
	{
		point[i] = a;
		i++;
	}
	return (b);
}
