/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:17:26 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/17 17:19:27 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int				i;

	i = 0;
	if (!s)
		return ;
	while (*(s + i))
	{
		ft_putchar(*(s + i));
		i++;
	}
	ft_putchar('\n');
}