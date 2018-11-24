/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:51:59 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/24 17:58:00 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int			index;
	int			i;

	index = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	while (index != n)
	{
		s1[i] = s2[index];
		index++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
