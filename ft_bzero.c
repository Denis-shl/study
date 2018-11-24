/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:20:20 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/22 15:25:40 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
void	ft_bzero(void *s, size_t n)
{
	int index;
	char *ma;

	ma = (char*) s;
	index = 0;
	if (n == 0)
		;
	else
		while (index != n)
		{
			*ma = 0;
			ma++;
			index++;
		}
}
