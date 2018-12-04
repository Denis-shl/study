/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:28:39 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/27 16:44:09 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;

	index = 0;
	str = NULL;
	if (!s || len == 0)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	while (*(s + start) && (index < len))
	{
		*(str + index) = *(s + start);
		index++;
		start++;
	}
	*(str + index) = '\0';
	return (str);
}
