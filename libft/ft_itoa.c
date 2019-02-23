/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:51:41 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/17 17:16:56 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int				i;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i = 1;
		n *= -1;
	}
	if (n > 0)
	{
		while (n > 0)
		{
			n /= 10;
			i++;
		}
	}
	return (i);
}

static char	*ft_min(int n, char *str)
{
	unsigned int	i;
	int				j;

	i = 2147483648;
	j = ft_len(n) - 1;
	str[0] = '-';
	while (j != 0)
	{
		str[j] = i % 10 + 48;
		i = i / 10;
		j--;
	}
	return (str);
}

static char	*ft_algor(int n, char *str)
{
	int i;
	int j;

	i = 0;
	j = ft_len(n) - 1;
	if (n == -2147483648)
	{
		str = ft_min(n, str);
		return (str);
	}
	if (n < 0)
	{
		i = 1;
		str[0] = '-';
		n *= -1;
	}
	while (j >= i)
	{
		str[j] = n % 10 + 48;
		n /= 10;
		j--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char		*str;
	int			i;

	str = NULL;
	i = ft_len(n);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	str[i] = '\0';
	str = ft_algor(n, str);
	return (str);
}
