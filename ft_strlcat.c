/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:56:10 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/24 17:56:43 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	strlcat(char *dst, const char *src, size_t size)
{
	size_t		index;
	size_t		n;

	n = size;
	index = 0;
	while (n != 0 && dst[n] != '\0')
	{
		n--;
	}
	while (src[index] != '\0' || n != size - 1)
	{
		dst[n] = src[index];
		n++;
		index++;
	}
}// надо потестить и понять работу!!!!!!!!
