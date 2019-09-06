/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:52:26 by oargrave          #+#    #+#             */
/*   Updated: 2019/09/06 14:17:51 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit(t_buff *buf)
{
	int index;

	index = 0;
	if (buf && buf->str != NULL)
	{
		ft_buffdel(&buf);
	}
	while (g_env[index] != NULL)
	{
		free(g_env[index]);
		index++;
	}
	free(g_env);
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
