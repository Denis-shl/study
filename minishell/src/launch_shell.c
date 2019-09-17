/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:53:23 by oargrave          #+#    #+#             */
/*   Updated: 2019/09/17 12:26:58 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char		*finding_ways(char *name)
{
	char			*way;
	char			*str;
	char			**all_the_way;
	int				index;

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
	if (str == NULL)
		return (NULL);
	all_the_way = ft_strsplit(str, ':');
	way = clean_way(all_the_way, name);
	free(str);
	delete_char(all_the_way);
	return (way);
}

static char		*ft_check(char **str)
{
	int				index;
	char			*way;
	struct stat		buf;

	index = ft_strlen(str[0]);
	if ((access(str[0], 0) == 0) && (access(str[0], 1) == 0))
	{
		stat(str[0], &buf);
		if ((buf.st_mode & S_IFMT) == S_IFDIR)
			return (NULL);
		way = ft_strdup(str[0]);
		return (way);
	}
	return (NULL);
}

static char		*lanunch_cur_dir(char **args)
{
	char			*way;
	char			*tmp;
	struct stat		buf;

	stat(args[0], &buf);
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		return (NULL);
	way = NULL;
	way = getcwd(NULL, MAX_DIR);
	if ((tmp = ft_check(args)) != NULL)
	{
		free(way);
		return (tmp);
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
	free(way);
	return (NULL);
}

int				ft_authorization(char *way, char **args)
{
	struct stat		buf;
	int				index;

	index = stat(way, &buf);
	if ((buf.st_mode & S_IRWXU) == 448)
		return (1);
	else if (index != -1)
	{
		free(way);
		ft_printf("%s: Permission denied\n", args[0]);
		return (2);
	}
	else if (index == -1)
	{
		free(way);
		return (0);
	}
	return (1);
}

int				launch_shell(char **args)
{
	pid_t			pid;
	pid_t			wpid;
	int				status;
	char			*way;
	int				i;

	if (!(way = finding_ways(args[0])))
		if ((way = lanunch_cur_dir(args)) == NULL)
		{
			free(way);
			return (0);
		}
	i = ft_authorization(way, args);
	if (i == 0)
		return (0);
	if (i == 2)
		return (1);
	pid = fork();
	if (pid == 0)
		execve(way, args, g_env);
	else
		wpid = wait(&status);
	free(way);
	return (1);
}
