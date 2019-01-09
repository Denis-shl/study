/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:09:19 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/27 15:23:38 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char							**str;
	int								i;
	int								y;
	int								k;
	int	size;

	y = 0;
	i = -1;
	if (!s || !c)
		return (NULL);
	size = ft_sizeword(s,c);
	if (!(str = (char**)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	while (++i < size)
	{
		k = 0;
		if (!(str[i] = ft_strnew(ft_sizesymbol(&s[y], c) + 1)))
			str[i] = NULL;
		while (s[y] == c)
			y++;
		while (s[y] != c && s[y])
			str[i][k++] = s[y++];
		str[i][k] = '\0';
	}
	str[i] = NULL;
	return (str);
}
