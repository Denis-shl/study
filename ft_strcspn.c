/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 03:54:16 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/24 18:21:36 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static void ft_algor(int *flag, int *length, int *size)
{
	if (*(flag) == 1)
	{
		*flag = 0;
		if (*length < *size)
			*length = *size;
		*size = 0;
	}
}
int ft_strcspn(const char *str, const char *sum)
{
	int i;
	int j;
	int size;
	int length;
	int flag;

	length = 0;
	size = 0;
	i = 0;
	if (!(*str) || (!(*sum)))
		return (0);
	while (*(str + i))
	{
		j = 0;
		while (*(sum + j))
		{
			if (*(sum + j) == *(str + i))
			{
				flag = 1;
				break ;
			}

			j++;
		}
		ft_algor(&flag, &length, &size);
		size++;
	i++;	
	}
	return (length);
}

int main ()
{
	char str1 [] = "1234567890";
	char str2 [] = "190";
	int i;
	i = ft_strcspn (str1,str2);
	printf ("i = %d \n",i);
	return (0);
}

