/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:53:23 by oargrave          #+#    #+#             */
/*   Updated: 2019/09/06 13:58:09 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char		*finding_ways(char *name)
{
	char		*way;
	char		*str;
	char		**all_the_way;
	int			index;

	str = NULL;
	index = 0;
	while (g_env[index])
	{
		if ((way = ft_strnstr(g_env[index], PATH, SIZE_PATH)) != NULL)
		{
			str = ft_strcpy(ft_strnew(ft_strlen(way) - 5), way + 5);
			break ;
		}
		index++;
	}
	all_the_way = ft_strsplit(str, ':');
	way = clean_way(all_the_way, name);
	free(str);
	delete_char(all_the_way);
	return (way);
}

static char		*lanunch_cur_dir(char **args)
{
	char		*way;
	char		*tmp;

	way = NULL;
	way = getcwd(NULL, MAX_DIR);
	if (access(args[0], 0) == -1)
	{
		return (NULL);
	}
	if (access(args[0], 1) == -1)
	{
		ft_printf("the file is not executable\n");
		return (NULL);
	}
	else
	{
		tmp = way;
		way = ft_strjoin(way, "/");
		free(tmp);
		tmp = ft_strjoin(way, args[0]);
		free(way);
		return (tmp);
	}
	return (NULL);
}

int				launch_shell(char **args)
{
	pid_t		pid;
	pid_t		wpid;
	int			status;
	char		*way;

	if (!(way = finding_ways(args[0])))
	{
		if ((way = lanunch_cur_dir(args)) == NULL)
		{
			free(way);
			return (0);
		}
	}
	pid = fork();
	if (pid == 0)
		execve(way, args, g_env);
	else
		wpid = wait(&status);
	free(way);
	return (1);
}
