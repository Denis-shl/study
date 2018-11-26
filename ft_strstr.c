/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:04:30 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/26 15:14:08 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	char		*point;
	int			i;
	int			j;
	int			z;

	point = NULL;
	i = -1;
	if (!ft_strlen(needle))
			return ((char *)haystack);
	while (*(haystack + ++i))
	{
		if (*(haystack + i) == *(needle + 0) && (point = (char *) (haystack + i)))
		{
			j = -1;
			z = i;
			while (*(needle + ++j) && point)
				if (*(needle + j) != (*(haystack + z++)))
					point = NULL;
			if (point)
				return (point);
		}
	}
	return (NULL);
}
