/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:09:19 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/26 20:12:29 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char							**str;
	int								i;
	int								y;
	int								k;

	y = 0;
	i = -1;
	if (!s || !c)
		return (NULL);
	if (!(str = (char**)malloc(sizeof(*str) * (ft_sizeword(s, c) + 1))))
		return (NULL);
	while (++i < ft_sizeword(s, c))
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
