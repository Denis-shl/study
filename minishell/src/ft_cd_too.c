/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_too.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:12:43 by oargrave          #+#    #+#             */
/*   Updated: 2019/09/17 10:50:52 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*home_dir(void)
{
	int				index;
	char			*home;

	index = 0;
	home = NULL;
	while (g_env[index] != NULL)
	{
		if (((home = ft_strstr(g_env[index], "HOME=/")) != NULL))
		{
			home = home + 5;
			return (home);
		}
		index++;
	}
	return (NULL);
}

void	ft_til(char *current_dir, char *new_dir, char *str, char **command)
{
	char *tmp;

	if (!(new_dir = home_dir()))
		new_dir = HOME_DIR;
	str = ft_strcpy(ft_strnew(ft_strlen(command[1])), command[1]);
	str++;
	tmp = ft_strnew(ft_strlen(new_dir) + ft_strlen(str) + 1);
	ft_strcpy(tmp, new_dir);
	tmp = ft_strcat(tmp, str);
	chdir(tmp);
	change_env(current_dir);
	free(--str);
	free(tmp);
	return ;
}

int		ft_check_dir(char *str)
{
	DIR			*dir;

	if (ft_strcmp(PREV_DIR, str) == 0)
		return (2);
	dir = opendir(str);
	if (dir == NULL)
		return (0);
	else
		closedir(dir);
	return (1);
}

int		ft_cd_com(char **command, char *new_dir, char *current_dir, char *str)
{
	if (command[1] == NULL)
	{
		if (!(new_dir = home_dir()))
			new_dir = HOME_DIR;
		chdir(new_dir);
		change_env(current_dir);
		return (0);
	}
	if (command[1][0] == '~')
	{
		ft_til(current_dir, new_dir, str, command);
		return (0);
	}
	if (command[1][0] == '/' && command[1][1] == '\0')
	{
		chdir("/");
		change_env(current_dir);
		return (0);
	}
	return (1);
}

void	ft_cd(char **command)
{
	char	*new_dir;
	char	*str;
	char	*current_dir;
	int		flag;

	flag = 0;
	current_dir = getcwd(NULL, MAX_DIR);
	if (ft_cd_com(command, new_dir, current_dir, str) == 0)
	{
		free(current_dir);
		return ;
	}
	if (ft_check_dir(command[1]) == 0)
	{
		ft_printf("cd: not a directory: %s\n", command[1]);
		free(current_dir);
		return ;
	}
	ft_cd_way(command, current_dir, str, new_dir);
	free(current_dir);
}
