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
#include <stdio.h>
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
		point[index] = NULL;
		index--;
	}
	free(point);
	printf("%p\n",point[0]);
}

int main()
{
	int i=0;
	int j=0;
	char **point;
	point = (char**)malloc(sizeof(char*) * 11);
	point[10] = 0;
	while(j != 10)
	{	
		i = 0;
		point[j] = (char*)malloc(sizeof(char) * 11);
		while (i != 10)
		{
			point[j][i] = '1';
			i++;
		}
		point[j][i] = '\0';
		printf("%s\n",point[j]);
	j++;
	}
	ft_memdel((void**)point);
	return (0);
}
