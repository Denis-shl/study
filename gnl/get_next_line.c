/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:11:10 by oargrave          #+#    #+#             */
/*   Updated: 2019/02/06 19:10:40 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


t_list *ft_get(t_list **file, int fd)
{
	t_list *tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!tmp)
		tmp = ft_lstnew("",fd);
//	tmp->content = "\0";
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}


char *ft_get_next(char **line, t_list *point)
{
	size_t i;
	char *del;

	if (ft_strchr((char *)point->content,'\n'))
	{
		*line = ft_strsub((char *)point->content, 0,\
		ft_strchr((char *)point->content,'\n') - (char *) point->content);
		i = ft_strchr((char *)point->content,'\n') - (char *) point->content;
		del = point->content;
		if (i < ft_strlen((char *)point->content))
		{
			ft_bzero((char *)point->content, i);
			point->content = ft_strdup(point->content + i + 1);

		}
		free (del);
	}
	else
	{
		del = point->content; 
		*line = ft_strncpy(ft_strnew(ft_strlen(point->content)), (char *)point->content, ft_strlen(point->content));
		point->content = ft_strdup( point->content + ft_strlen(point->content));
		free(del);
	//	printf ("ElSE");
	}
	return (*line);
}

int	get_next_line(const int fd, char **line)
{
    char *buf;
	int i;
	static t_list *file;
	t_list *point;
	char *del;

	*line = NULL;
	if (!(fd) || !(line) || !(BUFF_SIZE))
		return (-1);
	if (!(buf = (char*)malloc (sizeof (char) * (BUFF_SIZE + 1))))
		return (-1);
	point = ft_get(&file,fd);
	while (( i = read (fd, buf, BUFF_SIZE)))
	{
		buf[i] = '\0';
		del = point->content;
		point->content = ft_strjoin((char *)point->content,buf);
		free(del);
		if (ft_strchr((char *)point->content, '\n'))
			break ;
	}
	*line  = ft_get_next(line, point);
	free (buf);
	return (1);
}

int main (int argc, char **argv)
{
	char *line;
	int flags = O_RDONLY;
	int fd;
	int i;
//	char buuf;

	i = 0;
	if (!(fd = open (argv[1],flags)))
		return (0);
	printf ("fd = %d\n",fd);
	i = 0;
	if ((i = get_next_line(fd, &line)) == 1)
	{
		printf ("line 1:%s\n",line);
	} 
	if ((i = get_next_line(fd, &line)) == 1)
	{
		printf ("line 2:%s\n",line);
	}
//	free(line);
	
	if ((i = get_next_line(fd, &line)) == 1)
	{
		printf ("line 3:%s\n",line);
	}
	/*int fdd;
	if (!(fdd = open(argv[2], flags)))
		return (0);
	printf ("fdd = %d\n",fdd);
	if ((i = get_next_line(fdd, &line)) == 1)
	{
		printf ("%s\n",line);
	}	*/
	free(line);
	close(fd);
	argc = 1;
	return (0);
}
