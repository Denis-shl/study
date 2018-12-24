/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:09:19 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/24 20:46:34 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_size_word(char const *s, char c)
{
	unsigned int					i;
	unsigned int					word;

	i = 0;
	word = 0;
	while (*(s + i))
	{
		if (*(s + i) == c && *(s + i + 1) != c && *(s + i + 1) != '\0')
			word++;
		i++;
	}
	return (word);
}

static char			**ft_size_symbol(char **str, char const *s, char c)
{
	unsigned int						i;
	unsigned int						y;
	unsigned int						symbol;

	i = 0;
	y = 0;
	symbol = 0;
	while (*(s + i) != '\0')
	{
		while (*(s + i) != c && *(s + i) != '\0')
		{
			i++;
			symbol++;
		}
		if (symbol != 0)
		{
			if (!(str[y] = (char*)malloc(sizeof(char) * symbol + 1)))
				return (0);
			y++;
		}
		symbol = 0;
		i++;
	}
	return (str);
}

static char			**ft_algor(char **str, char const *s, char c)
{
	unsigned int				j;
	unsigned int				y;
	unsigned int				i;

	y = 0;
	j = 0;
	i = 0;
	while (*(s + i))
	{
		while ((*(s + i) != c) && (*(s + i) != '\0'))
		{
			str[y][j] = *(s + i);
			j++;
			i++;
		}
		if (j != 0)
		{
			str[y][j] = '\0';
			y++;
		}
		j = 0;
		if (*(s + i) == '\0')
			break ;
		i++;
	}
	return (str);
}

char				**ft_strsplit(char const *s, char c)
{
	char							**str;
	unsigned int					size;

	size = 0;
	str = NULL;
	if (!(s))
		return (0);
	size = ft_size_word(s, c);
	if (!(str = (char**)malloc(sizeof(char*) * size + 1)))
		return (0);
	str[size] = NULL;
	str = ft_size_symbol(str, s, c);
	str = ft_algor(str, s, c);
	return (str);
}
