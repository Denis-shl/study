/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:20:20 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/24 21:06:03 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	int index;
	char *point;

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
