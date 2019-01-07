/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:08:42 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/26 18:44:42 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	unsigned int	index;

	index = 0;
	if (!s1 || !s2)
		return (0);
	while (*(s1 + index) || *(s2 + index))
	{
		if (*(s1 + index) != *(s2 + index))
			return (0);
		index++;
	}
	return (1);
}
