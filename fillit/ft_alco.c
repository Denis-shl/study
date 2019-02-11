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
	/*if (!map[i])
		return (NULL);*/
	while (map[i] && map[i] != '.')
		i++;
	/*if (map[i] == '\0')
		return (NULL);*/
	return (i);
}


int		check_for_fit(char *map,t_list *point) //проверяет можно ли подставить тетринку на найденную координату точки и возвращает значение разницы, на которую надо смещать тетринку
{	
	char name;
	int pos;
	int i = -1;

	pos = 0;
	name = 'A';
	while (point)
	{
		i++;
		if (!(ft_algorithm(point, map, pos + 1, name)))
			return (0);
		point = point->next;
		if ((point) != NULL)
		{
				if (!(ft_algorithm((point), map, pos, name + 1)))
					return (0);
				else 
					point = point->next;
		}

	}

	return (1);
	
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

	map = (char *)malloc(sizeof(char) * size_map * size_map + size_map + 1);
	check_first(map, size_map);
	if (!(check_for_fit(map, point)))
	{
		free(map);
		return (ft_alco(point, size_map + 1));
	}
	return (map);
}

int		ft_algorithm(t_list *point, char *map, int pos, char name)
{
	int *cor;
	int i;
	int j;
	char *nam;

	j = 0;
	i = 0;
	cor = (int *)point->content_size;
	cor = ft_difference(cor, pos, map, 0);
	//printf ("pos %d",pos);
	if (pos > (int)(ft_strlen(map) - 3))
	{
		printf ("ERRRRORR");
		return (0);
	}
	/*while (i < 4)
	{
		printf("\n%d ", cor[i]);
		i++;
	}*/
	i = 0;
	nam = point->content;
	while (i < 4)
	{
		while (j < 4)
		{
			if ((map[cor[j]] != '.'))
				return (ft_algorithm(point, map, pos + 1, name));
			j++;
		}
		map[cor[i]] = nam[ft_strlen(nam) - 1];
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
		printf ("in[%d]%d\n", i, in[i]);
		if (i % 4 == 0)
			printf("\n");
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