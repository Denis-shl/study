/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:51:59 by oargrave          #+#    #+#             */
/*   Updated: 2019/08/05 15:56:08 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		index;
	int			i;

	index = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	while (index != n && s2[index] != '\0')
	{
		s1[i] = s2[index];
		index++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
