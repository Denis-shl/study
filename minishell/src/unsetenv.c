/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:49:40 by oargrave          #+#    #+#             */
/*   Updated: 2019/09/07 17:15:33 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_unsetenv(char **name)
{
	char			**new_env;
	unsigned int	index;
	unsigned int	jindex;

	index = 0;
	jindex = 0;
	if (name[1] == NULL ||
			(!(new_env = (char **)malloc(sizeof(char *) * (g_size_env + 1)))))
		return ;
	while (index < g_size_env)
	{
		if (ft_strncmp(g_env[index], name[1], ft_strlen(name[1])) != 0)
		{
			new_env[jindex] = ft_strnew(ft_strlen(g_env[index]));
			ft_strcpy(new_env[jindex], g_env[index]);
			jindex++;
		}
		index++;
	}
	g_size_env = jindex;
	new_env[jindex] = NULL;
	delete_char(g_env);
	g_env = new_env;
}
