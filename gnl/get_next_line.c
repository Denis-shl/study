/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:11:10 by oargrave          #+#    #+#             */
/*   Updated: 2019/01/31 12:09:52 by oargrave         ###   ########.fr       */
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


char *ft_get_next(char **line, t_list *point)
{
	size_t i;
	char *del; 

	if (ft_strchr((char *)point->content, '\n'))
	{
		i = ft_strchr((char *)point->content, '\n') - (char *)point->content;
		*line = ft_strsub((char *)point->content, 0, i);
		del = point->content;
		if (i < ft_strlen((char*)point->content))
				{
					point->content = ft_strdup((char *)point->content + i + 1);
					printf ("\npoint->content%s\n",point->content);
				//	ft_bzero((char *)point->content,i);
					free(del);
					del = NULL;
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
	printf ("fd = %d\n",fd);
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
	if ((i = get_next_line(fd, &line)) == 1)
	{
		printf ("good\n");
	}
	printf ("\n3:%s\n",line);
	int fdd;
	if (!(fdd = open(argv[2], flags)))
		return (0);
	printf ("fdd = %d\n",fdd);
	if ((i = get_next_line(fdd, &line)) == 1)
	{
		printf ("\ngood2:::::::%s",line);
	}	
	free(line);
	return (0);
}
