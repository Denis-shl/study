/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:23:28 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/24 18:03:45 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char		sumbol;
	char		*point;

	sumbol = c;
	point = NULL;
	while (*s)
	{
		if (*s == sumbol)
			point = s;
		s++;
	}
	if (point != NULL)
		return (point);
	return (NULL);
}
