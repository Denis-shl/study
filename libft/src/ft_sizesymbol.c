/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizesymbol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 19:56:23 by oargrave          #+#    #+#             */
/*   Updated: 2019/08/05 15:56:08 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_sizesymbol(char const *s, char c)
{
	int symbol;
	int i;

	i = 0;
	symbol = 0;
	while (s[i] == c)
	{
		i++;
	}
	while ((s[i] != c) && (s[i] != '\0'))
	{
		i++;
		symbol++;
	}
	return (symbol);
}
