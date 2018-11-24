/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:35:38 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/24 18:02:39 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strnlen(char *s1, size_t n)
{
	size_t			i;

	i = 0;
	while (i != n || s1[i] == '\0')
		i++;
	return (i);
}

/////

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int				i;
	size_t			l;

	if (0 == (l = ft_strnlen(needle, len)))
		return (haystack);
	while (*haystack != '\0')
	{
		if ((haystack[0] = needle[0]) && (0 == ft_strncmp(haystack, needle, l)))
			return (haystack);
		haystack++;
	}
	return (NULL);
}
