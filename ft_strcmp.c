/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:40:03 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/17 16:55:24 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int			i;

	i = 0;
	if (!(ft_strlen(s1)) && !(ft_strlen(s2)))
		return (0);
	while ((*(s1 + i) == *(s2 + i)) && (*(s1 + i)))
	{
		i++;
	}
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}
