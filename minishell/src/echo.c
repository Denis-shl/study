/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:57:52 by oargrave          #+#    #+#             */
/*   Updated: 2019/09/06 13:28:18 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_echo_dol(char **str)
{
	int index;
	char *var_env;
	char *tmp;

	index = 0;
	var_env = str[1];
	var_env++;
	while (g_env[index] != NULL)
	{
		if ((tmp = ft_strnstr(g_env[index], var_env, ft_strlen(var_env))) != NULL)
		{
			tmp += ft_strlen(var_env) + 1;
			ft_printf ("%s\n", tmp);
			return ;
		}
		index++;
	}
	ft_printf ("%s\n", str[1]);
} 

void	ft_echo(char **str)
{
	int		index;

	index = 1;
	del_commas(str);
	
	if (str[1] != NULL && ft_strcmp(str[1], NOTNEWLINE) == 0)
		return ;
	if (str[1] != NULL && str[1][0] == '$')
	{
		ft_echo_dol(str);
		return ;
	}
	while (str[index] != NULL)
	{
		write(1, str[index], ft_strlen(str[index]));
		write(1, " ", 1);
		index++;
	}
	ft_putchar('\n');
}
