/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:43:08 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/05 18:50:14 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void  ft_min (int fd)
{
	int  index;
	char *a;
	
	index = 0;
	a = "-2147483648";
	while (index <= 11)
	{
		ft_putchar_fd(a[index], fd);
		index++;
	}
}

void  ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_min(fd);
		return ;
	}
	else
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
	if (n > 10)
		ft_putnbr_fd(n / 10, fd);
	if (n >= 0)
		ft_putchar_fd(n % 10 + 48, fd);
}
