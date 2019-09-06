/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:28:50 by oargrave          #+#    #+#             */
/*   Updated: 2019/09/06 11:43:57 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// int		ft_matrlen(char **str)
// {
// 	int		index;

// 	index = 0;
// 	if (str == NULL)
// 		return (0);
// 	while (str[index] != NULL)
// 		index++;
// 	return (index);
// }

void	rewrite_env(char **env)
{
	size_t	size_en;
	int		i;
	int		j;

	size_en = 0;
	i = 0;
	g_size_env = ft_matrlen(env);
	if (!(g_env = (char **)malloc(sizeof(char *) * (g_size_env + 1))))
		ft_exit(NULL);
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], SHLVL, ft_strlen(SHLVL)) == 0)
			ft_shlvl(env[i]);
		if (!(g_env[i] = ft_strnew((ft_strlen(env[size_en]) + 1))))
			ft_exit(NULL);
		j = 0;
		while (env[i][j] != '\0')
		{
			g_env[i][j] = env[i][j];
			j++;
		}
		g_env[i][j] = '\0';
		i++;
		size_en++;
	}
}

void	ft_container(t_buff *buf)
{
	if (ft_pars(buf) == 0)
	{
		return ;
	}
	return ;
}

void	loop(int argc, char **argv)
{
	t_buff	*buf;
	char	sub;
	int		i;

	while (1)
	{
		buf = ft_buffinit(1000);
		write(1, "minishell ", 10);
		while ((i = (read(0, &sub, 1))))
		{
			if (sub == '\n')
				break ;
			if (i == 0)
				ft_exit(buf);
			ft_buffaddsymb(buf, sub);
		}
		ft_container(buf);
		ft_buffdel(&buf);
	}
}

int		main(int argc, char **argv, char **env)
{
	rewrite_env(env);
	loop(argc, argv);
	return (0);
}
