/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:24:30 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/09 23:54:01 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_algor(char const *s, int i, int i1, int i2)
{
	char *point;

	if (!(point = (char*)malloc(sizeof(char) * i + 1)))
		return (0);
	str[i] = '\0';
	i = 0;
	while (i1 <= i2)
	{
		str[i] = *(s + i1);
		i++;
		i1++;
	}

	return (str);
}

char	*ft_strtrim(char const *s)
{
	int i;
	int j;
	int i1;
	int i2;
	char *str;

	i = 0;
	if (!s)
		return (0);
	while (*(s + i))
	{
		i++;
		if (*(s + i) != ' ' || *(s + i) != ' \t' || *(s + i) != '\n')
			while (*(s + i) != '\0')
			{
				i++;
				i1 = i;
				j++;
			}
		while (*(s + j) == ' ' || *(s + j) == ' \t' || *(s + j) == '\n')
			j--;
		
	}
	i2 = j;
		str = ft_algor(s, i, i1, i2);
		return (str);
}	
