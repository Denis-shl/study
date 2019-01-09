/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:20:20 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/25 16:22:08 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		index;
	char		*point;

	index = 0;
	point = (char*)s;
	if (n == 0)
		;
	else
		while (index != n)
		{
			point[index] = '\0';
			index++;
		}
}
