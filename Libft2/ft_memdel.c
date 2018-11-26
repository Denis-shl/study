/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:50:57 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/26 17:21:44 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_memdel(void **ap)
{
	int index;
	char **point;


	point = (char **)ap;
	index = 0;
	while (point[index] != 0)
	{
		index++;
	}
	while (index >= 0)
	{
		free(point[index]);
		index--;
	}
	free(point);
}
