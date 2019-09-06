/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inline_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:16:42 by oargrave          #+#    #+#             */
/*   Updated: 2019/09/06 13:55:48 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(void)
{
	int		index;

	index = 0;
	while (g_env[index] != NULL)
	{
		printf("%s\n", g_env[index]);
		index++;
	}
}

void	del_commas(char **str)
{
	int index;
	int jindex;

	index = 0;
	while (str[index] != NULL)
	{
		jindex = 0;
		while (str[index][jindex] != '\0')
		{
			if (str[index][jindex] == '"')
				str[index][jindex] = 1;
			jindex++;
		}
		index++;
	}
}

char	*ft_search(char *str)
{
	int		index;
	char	*command;
	char	**tmp;

	index = 0;
	while (g_env[index] != NULL)
	{
		if (ft_strncmp(g_env[index], str, ft_strlen(str)) == 0)
		{
			tmp = ft_strsplit(g_env[index], '=');
			command = ft_strdup(tmp[1]);
			delete_char(tmp);
			printf("%s\n", command);
			return (command);
		}
		index++;
	}
	return (NULL);
}

int		ft_dollar(char **command)
{
	int		index;
	char	*str;
	char	*com;
	char	**new_command;
	char	*line;

	com = NULL;
	line = command[0];
	index = 0;
	str = ft_strdup(line + 1);
	com = ft_search(str);
	if (com != NULL)
	{
		new_command = (char **)malloc(sizeof(char) * 2);
		new_command[0] = com;
		new_command[1] = NULL;
		if ((inline_function(new_command) == 0))
			{
				if (ft_strncmp(new_command[0], HOME_DIR, SIZE_HOME_DIR) != 0
				|| (ft_strncmp(new_command[0], "/", 1) != 0))
					launch_shell(new_command);
			}
		delete_char(new_command);
		free(str);
	}
	else
		printf("%s: Uwndefined variable.\n", str);
	return (0);
}

int		inline_function(char **command)
{
	int		index;
	
	index = 0;
	if (ft_strncmp(command[0], ECHO, SIZE_ECHO) == 0)
		ft_echo(command);
	else if (ft_strncmp(command[0], CD, SIZE_CD) == 0)
		ft_cd(command);
	else if (ft_strncmp(command[0], SETENV, SIZE_SETENV) == 0)
		ft_setenv(command);
	else if (ft_strncmp(command[0], UNSETENV, SIZE_UNSETENV) == 0)
		ft_unsetenv(command);
	else if (ft_strncmp(command[0], ENV, G_SIZE_ENV_NAME) == 0)
		ft_env();
	else if (command[0][0] == DOLL)
		ft_dollar(command);
	else if (ft_strncmp(command[0], EXIT, SIZE_EXIT) == 0)
		return (-1);
	else
		return (0);
	return (1);
}
