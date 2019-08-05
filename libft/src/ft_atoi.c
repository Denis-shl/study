/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:08:20 by oargrave          #+#    #+#             */
/*   Updated: 2019/08/05 15:56:08 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	long long			flag;
	long long			res;
	long long			i;

	flag = 1;
	res = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	if (*str == '-' && str++)
		flag = -1;
	else if (*str == '+' && str++)
		;
	while ((*str >= '0') && (*str <= '9'))
	{
		i = res;
		res = res * 10 + (*str - '0');
		if (res < i && flag == 1)
			return (-1);
		else if (res < i && flag == -1)
			return (0);
		str++;
	}
	return ((int)res * flag);
}
