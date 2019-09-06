/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:57:52 by oargrave          #+#    #+#             */
/*   Updated: 2019/09/06 11:43:57 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_echo(char **str)
{
	int		index;

	index = 1;
	del_commas(str);
	matr_print(str);
	if (str[1] != NULL && ft_strcmp(str[1], NOTNEWLINE) == 0)
		return ;
	// if (str[1][0] == '$')
	// 	ft_d
	while (str[index] != NULL)
	{
		write(1, str[index], ft_strlen(str[index]));
		write(1, " ", 1);
		index++;
	}
	ft_putchar('\n');
}
