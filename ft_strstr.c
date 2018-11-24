/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:04:30 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/24 18:06:17 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	char		*point;

	point = NULL;
	while (*haystack != '\0')
	{
		if (*haystack == *needle)
		{
			point = haystack;
			while (*haystack == *needle)
			{
				haystack++;
				needle++;
			}
			if (*haystack != *needle)
			{
				point = NULL;
			}
			else
				return (point);
		}
		haystack++;
	}
	return (NULL);
}
