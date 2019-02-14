/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 10:00:33 by oargrave          #+#    #+#             */
/*   Updated: 2019/02/13 23:00:56 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*check(char **file, t_list *point, int i, int fd)
{
	char	*buf;
	t_list	*new;
	char	name;

	name = 'A';
	new = point;
	if (!(buf = (char *)malloc(sizeof(char) * 23)))
		return (0);
	if (!(fd = open(file[1], O_RDONLY)))
		return (0);
	while ((i = read(fd, buf, 21)))
	{
		buf[i] = '\0';
		if (!(check_buf(buf, 0, 0, 0)) || buf[0] == '\0')
			return (0);
		point = record(buf, point, name);
		name++;
	}
	close(fd);
	free(buf);
	return (point);
}

int		check_buf(char *buf, int i, int sharp, int point)
{
	int	len;
	int	poin;

	poin = 0;
	len = ft_strlen(buf);
	while (buf[i] != '\0')
	{
		if ((buf[i] != '.' && buf[i] != '#' && buf[i] != '\n') ||
		(buf[i] == '\n' && (i != 4 && i != 9 && i != 14 && i != 19 && i != 20)))
			return (0);
		if (buf[i] == '#')
			sharp++;
		else if (buf[i] == '\n')
			poin++;
		else
			point++;
		i++;
	}
	if (((sharp != 4 || point != 12) && (poin != 4 || poin != 5
					|| poin != 3)) || (!(check_tetriminos(buf, i))))
		return (0);
	return (1);
}

int		check_tetriminos(char *buf, int len)
{
	int	com;
	int	i;

	len = 1;
	com = 0;
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '#')
		{
			com += buf[i + 1] == '#' ? 1 : 0;
			com += buf[i + 5] == '#' ? 1 : 0;
			com += buf[i - 1] == '#' ? 1 : 0;
			com += buf[i - 5] == '#' ? 1 : 0;
		}
		i++;
	}
	if (buf[0] == '\0' || com < 6)
		return (0);
	return (1);
}

t_list	*record(char *buf, t_list *point, char name)
{
	t_list	*new;
	int		i;

	i = ft_strlen(buf);
	new = point;
	while (new)
		new = new->next;
	if (!new)
		new = ft_lstnew("", 1);
	buf[i] = name;
	buf[i + 1] = '\0';
	new->content = (char *)ft_strsub(buf, 0, 23);
	point->next = new;
	return (new);
}

int		record_name(t_list *point)
{
	char	*str;

	while (point->next)
		point = point->next;
	str = point->content;
	if ((str[19] == '\n' && str[20] == '\n') || (str[19] != '\n'))
		return (0);
	return (1);
}
