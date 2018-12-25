/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:09:19 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/25 22:13:00 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static  int		ft_size_word(char const *s, char c)
{
	unsigned int					i;
	int								word;

	i = 0;
	word = 0;
	while (*(s + i))
	{
		 while (*(s + i) == c)
				i++;
		if (*(s + i) != c &&  *(s + i) != '\0')
			word++;
		while (*(s + i) != c && *(s + i) != '\0')
			i++;
	}
	return (word);
}

static int		ft_size_symbol( char const *s, char c)
{
	unsigned int						y;
	unsigned int						symbol;
	unsigned int						i;

	i = 0;
	y = 0;
	symbol = 0;
		while (*(s + i) == c && *(s + i) != '\0')
		{
			i++;
		}
		while ((*(s+ i) != c) && (*(s + i) != '\0'))
		{
			i++;
			symbol++;
		}
	return (symbol);
}

char				**ft_strsplit(char const *s, char c)
{
	char							**str;
	int								size;
	int								i;
	int								y;
	int								k;

	y = 0;
	i = -1;
	size = ft_size_word(s, c);
	if (!(s))
		return (0);
	if (!(str = (char**)malloc(sizeof(char*) * size + 1)))
		return (0);
	while (++i < size)
	{
		k = 0;
		if (!(str[i] = ft_strnew(ft_size_symbol(&s[y], c) + 1)))
			str[i] = NULL;
		while (s[y] == c)
			y++;
		while (s[y] != c && s[y])
			str[i][k++] = s[y++];
		str[i][k] = '\0';
	}
	str[i] = 0;
	return (str);
}
