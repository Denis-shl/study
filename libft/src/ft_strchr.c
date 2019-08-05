/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:12:32 by oargrave          #+#    #+#             */
/*   Updated: 2019/08/05 15:56:08 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char		sumbol;
	int			index;

	sumbol = c;
	index = 0;
	if (*s == sumbol)
		return ((char*)s);
	while (*s != '\0')
	{
		if (*s == sumbol)
		{
			return ((char*)s);
		}
		s++;
		if (*s == sumbol)
			return ((char*)s);
	}
	return (0);
}
