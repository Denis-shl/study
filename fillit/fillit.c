/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:17:07 by qmebble           #+#    #+#             */
/*   Updated: 2019/02/12 18:29:26 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		i;
	int		size;
	char	*map;
	t_list	*point;
	t_list	*new;

	i = 0;
	map = NULL;
	size = 0;
	point = ft_lstnew("", 1);
	if (argc != 2 || !(new = check(argv, point, i, size)) ||
		!(record_name(point)))
		return (0);
	i = generic_map(point);
	point = point->next;
	new = point;
	point = ft_list(point, new, size);
	map = ft_alco(point, i); //ИСПРАВИТЬ 5
	//printf("%s", map); //УБРАТЬ
	i = 0;
	while (map[i] != '\0')
	{
		ft_putchar(map[i]);
		i++;
	}
	return (0);
}

t_list	*ft_list(t_list *point, t_list *start, int size)
{
	int		**ar;
	char	*str;
	int		i;

	while (point)
	{
		size++;
		point = point->next;
	}
	ar = (int**)malloc(sizeof(int*) * size);
	i = size;
	size = 0;
	point = start;
	while (i != size)
	{
		if (!(ar[size] = (int *)malloc(sizeof(int) * 4)))
			return (0);
		point->content_size = (size_t)ar[size];
		str = point->content;
		ft_list_red(ar, str, size);
		size++;
		if (point->next != NULL)
			point = point->next;
	}
	return (start);
}

void	ft_list_red(int **ar, char *str, int siz)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			ar[siz][j] = i;
			j++;
		}
		i++;
	}
}
