/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:11:10 by oargrave          #+#    #+#             */
/*   Updated: 2019/01/08 12:39:19 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int	get_next_line(const int fd, char **line)
{
	int i;
	int j = 0;
    char buf[BUFF_SIZE + 1];
	if (!(fd) || !(line) || !(BUFF_SIZE))
		return (-1);
	buf[BUFF_SIZE] = '\0';
	while (( i = read (fd, buf, BUFF_SIZE)))
	{
		
	}
	printf ("%s\n",buf);
	line[0] = ft_strncpy(line[0],buf,BUFF_SIZE);
	return (0);
}




int main (int argc, char **argv)
{
	char **line;
	int flags = O_RDONLY;
	int fd;
	int i;
	char buuf;

	i = 0;
	if (!(line = (char**)malloc(sizeof(char*) * 2)))
		return (0);
	while ( i != 2)
	{
		if (!(line[i] = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (0); 
			i++;
	}
	line[0][BUFF_SIZE] = '\0';
	if (!(fd = open (argv[1],flags)))
		return (0);
	i = 0;
	if ((i = get_next_line(fd, line)) == 1)
	{
		printf ("good");
	} 
	printf ("%s",line[0]);
	close (fd);
	
	return (0);
}
