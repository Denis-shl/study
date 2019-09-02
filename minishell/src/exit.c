/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:52:26 by oargrave          #+#    #+#             */
/*   Updated: 2019/09/02 17:52:57 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_exit(t_buff *buf)
{
	if (buf && buf->str != NULL)
	{
		ft_buffdel(&buf);
	}
	exit(0);
}

void	ft_shlvl(char *str)
{
	int		index;
	char	*tmp;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] >= 48 && str[index] < 57 && str[index + 1] == '\0')
			str[index]++;
		index++;
	}
}
