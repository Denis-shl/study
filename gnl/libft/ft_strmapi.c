/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:57:23 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/25 14:50:22 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*str;

	index = 0;
	str = NULL;
	if (!(s))
		return (0);
	while (*(s + index))
		index++;
	if (!(str = (char *)malloc(sizeof(char) * index + 1)))
		return (0);
	*(str + index) = '\0';
	index = 0;
	while (*(s + index))
	{
		*(str + index) = f(index, *(s + index));
		index++;
	}
	return (str);
}
