/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:25:23 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/17 17:02:02 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t			index;

	index = 0;
	while (index < len)
	{
		if (src[index] != '\0')
			dst[index] = src[index];
		else
			while (index < len)
			{
				dst[index] = '\0';
				index++;
			}
		index++;
	}
	return (dst);
}
