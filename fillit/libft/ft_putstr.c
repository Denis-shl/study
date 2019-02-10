/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:19:44 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/17 17:26:02 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int			index;
	char		*point;

	if (!s)
		return ;
	point = (char *)s;
	index = 0;
	while (*(point + index) != '\0')
	{
		ft_putchar(*(point + index));
		index++;
	}
}
