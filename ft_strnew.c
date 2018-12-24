/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:28:58 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/17 17:56:25 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*point;
	size_t			index;

	point = NULL;
	index = 0;
	if (!(point = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	point[size] = '\0';
	while (index < size)
	{
		point[index] = '\0';
		index++;
	}
	return (point);
}
