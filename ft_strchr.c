/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:12:32 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/24 17:53:11 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char		sumbol;

	sumbol = c;
	while (*s)
	{
		if (*s == sumbol)
			return (s);
		s++;
	}
	return (NULL);
}
