/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:46:08 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/24 23:33:15 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcat(char *s1, const char *s2)
{
	int index;
	int i;

	i = 0;
	index = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[index])
	{
		s1[i] = s2[index];
		i++;
		index++;
	}
	s1[i] = '\0';
	return (s1);
}
