/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:59:10 by oargrave          #+#    #+#             */
/*   Updated: 2019/08/05 15:56:08 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		index;
	char	*mas;

	index = 0;
	while (s1[index] != '\0')
		index++;
	if (!(mas = (char*)malloc(sizeof(char) * index + 1)))
		return (0);
	index = 0;
	while (s1[index] != '\0')
	{
		mas[index] = s1[index];
		index++;
	}
	mas[index] = '\0';
	return (mas);
}
