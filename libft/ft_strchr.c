/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:12:32 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/25 20:44:51 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
