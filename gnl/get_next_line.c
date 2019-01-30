/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:11:10 by oargrave          #+#    #+#             */
/*   Updated: 2019/01/30 23:03:01 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


t_list *ft_get(t_list **file, int fd)
{
	t_list *tmp;

	tmp = *file;
	while (tmp)
	{
		if (tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!tmp)
		tmp = ft_lstnew("",fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

size_t	ft_size_len (t_list *point)
{
	char *str;
	size_t i;

	str = point->content;
	i = 0;
	while (str[i] != '\0' || str[i] != '\n')
	{
		if (str[i] == '\n')
		{
			return (i);
			break ;
		}
		i++;
	}
	return (i);
}

char *ft_get_next(char **line, t_list *point)
{
	size_t i;

	i = ft_strchr((char *)point->content, '\n') - (char *)point->content;
	if (ft_strchr((char *)point->content, '\n'))
	{
		*line = ft_strsub((char *)point->content, 0, i);
		if (i < ft_strlen((char*)point->content))
				{
					point->content = ft_strdup((char *)point->content + i + 1);
					(char *)point->content = ft_bzero(point->content);
				}

	}
	else 
	{
		i = ft_strlen((char *)point->content);
		*line = ft_strncpy(ft_strnew(i), (char *)point->content, i);
		point->content = ft_strdup((char *)point->content + i);
	}
	return (*line);
}

int	get_next_line(const int fd, char **line)
{
    char *buf;
	static t_list *file;
	t_list *point;
	int i;

	*line = NULL;
	if (!(fd) || !(line) || !(BUFF_SIZE))
		return (-1);
	if (!(buf = (char*)malloc (sizeof (char) * (BUFF_SIZE + 1))))
		return (-1);
	point = ft_get(&file,fd);
	while (( i = read (fd, buf, BUFF_SIZE)))
	{
		buf[i] = '\0';
		point->content = ft_strjoin((char *)point->content,buf);
		if (ft_strchr((char *)point->content, '\n'))
			break ;
	}
	*line  = ft_get_next(line, point);
	buf = NULL; 
	return (1);
}

int main (int argc, char **argv)
{
	char *line;
	int flags = O_RDONLY;
	int fd;
	int i;
	char buuf;

	i = 0;
	if (!(fd = open (argv[1],flags)))
		return (0);
	i = 0;
	if ((i = get_next_line(fd, &line)) == 1)
	{
		printf ("good\n");
	} 
	printf ("\n 1:%s\n",line);
	if ((i = get_next_line(fd, &line)) == 1)
	{
		printf ("good\n");
	}
	printf ("\n2:%s\n",line);
	close (fd);
	free(line);
	return (0);
}
