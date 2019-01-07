/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 03:54:16 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/26 19:54:57 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_algor(int *flag, int *length, int *size)
{
	if (*(flag) == 1)
	{
		*flag = 0;
		if (*length < *size)
			*length = *size;
		*size = 0;
	}
	else
		*size = *size + 1;
}

int			ft_strcspn(const char *str, const char *sum)
{
	int i;
	int j;
	int size;
	int length;
	int flag;

	length = 0;
	size = 0;
	i = -1;
	if (!(*str) || (!(*sum)))
		return (0);
	while (*(str + ++i))
	{
		j = -1;
		while (*(sum + ++j))
		{
			if (*(sum + j) == *(str + i))
			{
				flag = 1;
				break ;
			}
		}
		ft_algor(&flag, &length, &size);
	}
	return (length);
}
