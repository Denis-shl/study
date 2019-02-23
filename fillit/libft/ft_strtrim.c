/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:24:30 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/24 16:33:10 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_algor(char const *s, char *str, unsigned int size)
{
	unsigned int j;
	unsigned int i;

	i = 0;
	j = 0;
	while (*(s + i) == '\t' || *(s + i) == '\n' || *(s + i) == ' ')
		i++;
	while (j < size)
	{
		str[j] = *(s + i);
		i++;
		j++;
	}
	return (str);
}

static int	ft_size(char const *s)
{
	unsigned int	i;
	unsigned int	y;
	unsigned int	j;

	i = 0;
	y = 0;
	while (*(s + i) == '\t' || *(s + i) == '\n' || *(s + i) == ' ')
	{
		i++;
	}
	if (*(s + i) == '\0')
		return (0);
	j = i;
	while (*(s + i))
		i++;
	i--;
	while (*(s + i) == '\t' || *(s + i) == '\n' || *(s + i) == ' ')
	{
		i--;
		y += 1;
	}
	i = ft_strlen(s);
	return (i - (j + y));
}

char		*ft_strtrim(char const *s)
{
	unsigned int	size;
	char			*str;

	if (!s)
		return (0);
	size = ft_size(s);
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (0);
	str[size] = '\0';
	str = ft_algor(s, str, size);
	return (str);
}
