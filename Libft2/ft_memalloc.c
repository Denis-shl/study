/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:49:04 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/26 16:50:52 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <lidft.h>
#include <stdlib.h>
#include <stdio.h>
void	*ft_memalloc(size_t size)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) *size)))
		return (0);
	str[size - 1] = '\0';
	while (str[i] != '\0')
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}

int main ()
{
	char *z;
	z = NULL;

	z = (char*)ft_memalloc(15);
	printf ("%p \n",z);
	return (0);
}
