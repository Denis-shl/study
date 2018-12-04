/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:51:41 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/04 20:19:05 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int ft_len(int n)
{
	int j;

	j = 0;
	if (n == 0)
		return (1);
//	if (n == -2147483648)
//	{
//		j = 12;
//		return (12);
//	}
	if (n < 0)
	{
		
		n *= -1;
		j++;
	}
	while (n > 0)
	{
		n /= 10;
		j++;
	}
	return (j);
}
static	char	*ft_min_max(int n, char  *str)
{

	if (n == -2147483648)
	{
		str = "-2147483648";
		return (str);
	}
	if (n == 2147483647)
	{
		str = "2147483647";
		return (str);
	}
	return (str);
}


static char	*ft_algoritm(int n, char *str)
{
	int i;
	int j;

	i = 0;
	if (n == -2147483648 || n == 2147483647)
	{
		str = ft_min_max(n,str);
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		i = 1;
		n *= -1;
	}
	j = ft_len(n);
	while (n > 0)
	{
		str[j] = n % 10 + 48;
		n /= 10;
		j--;
	}
	return (str);
}


char	*ft_itoa(int n)
{
	char *str;

	str = 0;
	int i;
	  if (n == -2147483648)
	  
		  i = 11;
	  else
		  i = ft_len(n);
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (0);
	str[i] = '\0';
	str = ft_algoritm(n,str);
	return (str);
}
