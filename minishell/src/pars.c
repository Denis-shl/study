/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:23:17 by oargrave          #+#    #+#             */
/*   Updated: 2019/09/17 12:37:18 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	delete_char(char **str)
{
	int		index;

	index = 0;
	if (!str)
		return ;
	if (str[0] == NULL)
	{
		free(str);
		return ;
	}
	while (str[index])
		index++;
	while (index >= 0)
	{
		free(str[index]);
		index--;
	}
	free(str);
	str = NULL;
}

int		check_dirs(char *way, char *tmp, struct stat buf)
{
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
	{
		free(way);
		free(tmp);
		return (-1);
	}
	return (0);
}

char	*clean_way(char **str, char *name)
{
	int			index;
	char		*way;
	char		*tmp;
	struct stat	buf;

	index = 0;
	while (str[index] != NULL)
	{
		tmp = ft_strjoin(str[index], "/");
		way = ft_strjoin(tmp, name);
		if (access(way, 0) == 0 && access(way, 1) == 0)
		{
			stat(way, &buf);
			if (check_dirs(way, tmp, buf) == -1)
				return (NULL);
			free(tmp);
			return (way);
		}
		index++;
		free(way);
		free(tmp);
	}
	return (NULL);
}

void	ft_shell_or_launc(char **str, char **command, int flag)
{
	if (command[0] == NULL)
		return ;
	if ((flag = inline_function(command)) == 1)
		;
	else if (flag == -1)
	{
		delete_char(command);
		delete_char(str);
		ft_exit(NULL);
	}
	else
		flag = launch_shell(command);
	if (flag == 0)
		ft_printf("minishell: command not found:%s\n", command[0]);
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
