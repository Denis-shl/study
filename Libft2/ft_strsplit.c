/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:39:44 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/04 17:51:18 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_strsplit(char const *s, char c)
{
	char **str;
	int i;

	i = 0;
	if (!s)
		return (0);
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			j++;
		i++;
	}
	if (!(str = (char *)malloc(char(sizeof(char *) * j + 1))))
		return (0);



