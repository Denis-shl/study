/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:11:10 by oargrave          #+#    #+#             */
/*   Updated: 2019/01/10 18:07:46 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int	get_next_line(const int fd, char **line)
{
	int i = 0;
	int j = 0;
    char *buf;
	*line = NULL;
	char *point;

	point = NULL;
	if (!(fd) || !(line) || !(BUFF_SIZE))
		return (-1);
	if (!(buf = (char*)malloc (sizeof (char) * (BUFF_SIZE + 1))))
		return (-1);
	while (( i = read (fd, buf, BUFF_SIZE)))
	{
		buf[i] = '\0';
	}
	printf ("%s\n",buf);
	point  = ft_strjoin(point,buf);
	free(buf);
	line = &point;
	printf ("%s\n %s\n",*line,buf); 
	return (0);
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
		printf ("good");
	} 
//	printf ("%s",line[0]);
	close (fd);
	printf ("%s\n",line);
	return (0);
}
