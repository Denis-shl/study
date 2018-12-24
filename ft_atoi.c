/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:08:20 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/24 20:04:26 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			flag;
	long long	res;

	flag = 1;
	res = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+' && str++)
	{
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((int)res * flag);
}
