/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 23:21:52 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/17 17:52:54 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int				s;
	int				i;
	int				j;
	char			*str;

	i = 0;
	j = 0;
	if (!(s1) || !(s2))
		return (NULL);
	s = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = (char*)malloc(sizeof(char) * s)))
		return (NULL);
	while (*(s1 + i) != '\0')
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + j) != '\0')
	{
		*(str + i) = *(s2 + j);
		i++;
		j++;
	}
	*(str + i) = '\0';
	return (str);
}
