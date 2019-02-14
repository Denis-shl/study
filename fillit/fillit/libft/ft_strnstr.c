/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:07:12 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/25 17:11:58 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;
	int			found;

	i = -1;
	found = 1;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (*(haystack + ++i) && i < len)
	{
		j = 0;
		if (*(haystack + i) == *(needle + 0))
		{
			k = i;
			found = 1;
			while (*(haystack + k) && *(needle + j) && j < len && k < len)
				if (*(haystack + k++) != *(needle + j++))
					found = 0;
			if (found && !*(needle + j))
				return ((char *)haystack + i);
		}
	}
	return (NULL);
}
