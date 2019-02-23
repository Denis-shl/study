/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:19:47 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/25 14:51:04 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int				index;
	char			*str;

	index = 0;
	str = NULL;
	if (!s)
		return (0);
	while (*(s + index))
		index++;
	if (!(str = (char *)malloc(sizeof(char) * index + 1)))
		return (0);
	index = 0;
	while (*(s + index))
	{
		*(str + index) = f(*(s + index));
		index++;
	}
	*(str + index) = '\0';
	return (str);
}
