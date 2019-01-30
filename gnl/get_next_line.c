/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:11:10 by oargrave          #+#    #+#             */
/*   Updated: 2019/01/30 18:13:44 by oargrave         ###   ########.fr       */
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


char *ft_get_next(char **line, t_list point)
{
	if (




	return (*line);
}


int	get_next_line(const int fd, char **line)
{
	int i = 0;
	int j = 0;
    char *buf;
	char *poin;
	static t_list *file;

	*line = NULL;
	t_list *point;

	if (!(fd) || !(line) || !(BUFF_SIZE))
		return (-1);
	if (!(buf = (char*)malloc (sizeof (char) * (BUFF_SIZE + 1))))
		return (-1);
	point = ft_get(&file,fd);
//	point = ft_lstnew("", fd);
	while (( i = read (fd, buf, BUFF_SIZE)))
	{
		buf[i] = '\0';
		(*point).content = ft_strjoin((char *)point->content,buf);
		if (ft_strchr((char *)point->content, '\n'))
				break ;
	}
	*line  = point->content;
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
//	printf ("%s",line[0]);
	close (fd);
	printf ("%s",line);
	free(line);
	return (0);
}
