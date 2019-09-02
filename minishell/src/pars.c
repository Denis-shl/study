/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:23:17 by oargrave          #+#    #+#             */
/*   Updated: 2019/09/02 16:23:32 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	delete_char(char **str)
{
	int		index;

	index = 0;
	if (!str)
		return ;
	while (str[index] != NULL)
	{
		free(str[index]);
		index++;
	}
	free(str);
	str = NULL;
}

char	*clean_way(char **str, char *name)
{
	int		index;
	char	*way;
	char	*tmp;

	index = 0;
	way = 0;
	while (str[index] != NULL)
	{
		tmp = ft_strjoin(str[index], "/");
		way = ft_strjoin(tmp, name);
		if (access(way, 0) == 0)
			return (way);
		index++;
		free(way);
		free(tmp);
	}
	return (NULL);
}

void	ft_shell_or_launc(char **str, char **command, int flag)
{
	if ((flag = inline_function(command)) == 1)
		;
	else if (flag == -1)
	{
		delete_char(command);
		delete_char(str);
		exit(0);
	}
	else
		flag = launch_shell(command);
	if (flag == 0)
		ft_printf("command not found:%s\n", command[0]);
}

int		ft_pars(t_buff *buf)
{
	char	**str;
	char	**command;
	int		i;
	int		flag;

	command = NULL;
	i = 0;
	str = ft_strsplit(buf->str, ';');
	while (str[i] != NULL)
	{
		command = ft_strsplit(str[i], ' ');
		if (command[0] == NULL)
		{
			i++;
			continue ;
		}
		del_commas(command);
		ft_shell_or_launc(str, command, flag);
		delete_char(command);
		command = NULL;
		i++;
	}
	delete_char(str);
	return (1);
}
