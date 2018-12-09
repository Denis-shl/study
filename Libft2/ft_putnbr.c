/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:21:44 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/05 18:50:38 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_min (void)
{
	int  index;
	char *a;
	
	index = 0;
	a = "-2147483648";
	while (index <= 11)
	{
		ft_putchar(a[index]);
		index++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_min();
		return ;
	}
	else 
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
	if (n > 10)
		ft_putnbr(n / 10);
	if (n >= 0)
		ft_putchar(n % 10 + 48);
}
