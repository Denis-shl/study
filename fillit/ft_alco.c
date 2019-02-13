/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alco.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:40:48 by qmebble           #+#    #+#             */
/*   Updated: 2019/02/11 15:28:13 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_abs(int a)
{
	if (a < 0)
		return (-1 * a);
	return (a);
}

int		ft_pos(char *map, int start)		//Находит позицию первой попавшейся точки, стартуя от заданной позиции
{
	int	i;

	i = start;
	while (map[i] && map[i] != '.')
		i++;
	return (i);
}


void	check_first(char *map, int size_map) //при самом первом заходе в программу, создает карту размеров (size_map X size_map), состояющую из '.' и '\n'
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (map[i] != '.' && map[i] != '#')
	{
		while (i < size_map * size_map + size_map)
		{
			if (count == size_map)
			{
				map[i] = '\n';
				count = 0;
			}
			else
			{
				map[i] = '.';
				count++;
			}
			i++;
		}
		map[i] = '\0';
	}
	return ;
}

char	*ft_alco(t_list *point, int size_map)
{
	char	*map;

	if (!(map = (char *)malloc(sizeof(char) * size_map * size_map + size_map + 1)))
		return (0);
	check_first(map, size_map);
	if (!(check_for_fit(map, point, size_map)))
	{
		free(map);
		return (ft_alco(point, size_map + 1));
	}
	return (map);
}

int		check_for_fit(char *map,t_list *point, int i) //проверяет можно ли подставить тетринку на найденную координату точки и возвращает значение разницы, на которую надо смещать тетринку
{	
	int pos;
	t_list *present;

	pos = 0;
	while (pos < ((i * i)))
	{
		present = point;
		if (point == NULL)
			return (1);
		if (!(ft_algorithm(point, map, ft_pos(map, pos),present)))
		{
			pos++;
			continue ;
		}
		if (point->next == NULL || check_for_fit(map, point->next, i))
			return (1);
		else 
		new_map(map, point);
		pos++;
	}

	return (0);
	
}

int		ft_algorithm(t_list *point, char *map, int pos, t_list *start)
{
	int *cor;
	int i;
	int j;
	char *nam;
	int r;

	r = 0;
	i = 0;
	cor = (int *)point->content_size;
	cor = ft_difference(cor, pos, map, 0);

	nam = point->content;
	j = ft_strlen(nam);
	while (i != 4)
	{
		while (r != 4)
		{ 
			if (map[cor[r]] != '.')
				return (0);
			r++;
		}
			map[cor[i]] = nam[j - 1];
		i++;
	}
	return (1);
}

int		*ft_difference(int *cor, int pos,char *map, int len)
{
	int	i;
	unsigned int	difference;
	int j;
	int *in;

	in  = (int*)malloc(sizeof(int) * 4);
	i = 0;
	j = 0;

	while (map[len] != '\n')
	{
		len++;
	}
	//printf (" len = %d\n",len);
	difference = cor[0] - pos;
	//cor[0] = pos;
	while (i < 4)
	{
		if ((cor[i] - cor[i - 1]) > 1 && len <= 4)
			difference = difference + ft_abs(len - 4);
		else if ((cor[i] - cor[i - 1]) > 1 && len > 4)
			difference = difference - ft_abs(len - 4);
		in[j] = cor[j] - difference;
		//printf ("in[%d]%d\n", i, in[i]);
		//if (i % 4 == 0)
		//	printf("\n");
		i++;
		j++;
	}
	i = 0 ;
/*	while (i < 4)
	{
		printf("%d ", in[i]);
		i++;
	}*/
	
	return (in);
}
char	*new_map(char *map, t_list *point) //при самом первом заходе в программу, создает карту размеров (size_map X size_map), состояющую из '.' и '\n'
{
	int	i;
	int	count;
	char *str;
	char name;
//	printf ("map %s\n",map);

	str = point->content;
	name = str[ft_strlen(str) - 1];
//	printf ("\nname  %c\n",name);
	i = 0;
	count = 0;
	while (count != 4 && map[i] != '\0')
	{
		if (map[i] == name)
		{
			map[i] = '.';
			count++;
		}
		i++;

	}
//	printf ("new map = %s\n",map);
	return (map);
}