/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:09:48 by oargrave          #+#    #+#             */
/*   Updated: 2019/09/06 11:43:57 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	change_env(char *prev_dir)
{
	int		index;
	char	*current_dir;

	current_dir = getcwd(NULL, MAX_DIR);
	index = 0;
	while (g_env[index] != NULL)
	{
		if (ft_strnstr(g_env[index], PWD, 5) != NULL)
		{
			free(g_env[index]);
			g_env[index] = ft_strnew(MAX_DIR);
			ft_strcpy(g_env[index], PWD);
			g_env[index] = ft_strcat(g_env[index], current_dir);
		}
		if (ft_strnstr(g_env[index], OLDPWD, 8) != NULL)
		{
			free(g_env[index]);
			g_env[index] = ft_strnew(MAX_DIR);
			ft_strcpy(g_env[index], OLDPWD);
			g_env[index] = ft_strcat(g_env[index], prev_dir);
		}
		index++;
	}
	free(current_dir);
}

char	*pr_dir(void)
{
	char	*new_dir;
	int		index;

	index = 0;
	while (g_env[index] != NULL)
	{
		if ((new_dir = ft_strnstr(g_env[index], OLDPWD, 8)) != NULL)
			return (new_dir + 7);
		index++;
	}
	return (new_dir);
}

void	ft_cd_way(char **command, char *current_dir, char *str, char *new_dir)
{
	if (ft_check_dir(command[1]) == 1)
	{
		new_dir = ft_strjoin(current_dir, "/");
		str = new_dir;
		new_dir = ft_strjoin(new_dir, command[1]);
		chdir(new_dir);
		change_env(current_dir);
		free(new_dir);
		free(str);
	}
	else
	{
		new_dir = pr_dir();
		chdir(new_dir);
		change_env(current_dir);
		new_dir = getcwd(NULL, MAX_DIR);
		printf("%s\n", new_dir);
		free(new_dir);
	}
}
