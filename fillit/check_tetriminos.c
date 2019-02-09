#include "fillit.h"

t_list	*check(char **file, t_list *point)
{
	int fd;
	size_t i;
	char *buf;
	t_list  *new;
	char name;

	point = ft_lstnew("", 1);

	name = 'A';
	new = point;
	if (!(buf = (char *)malloc(sizeof(char) * 23)))
		return (0);
	if (!(fd = open(file[1], O_RDONLY)))
		return (0);
	while ((i = read(fd, buf, 21)))
	{
		buf[i] = '\0';
		if (!(check_buf(buf)))
			return (0);
		point = record(buf, point, name);
		name++;
	}
	close (fd);
	printf ("\n%s\n",point->content);
	return (point);
}

int check_buf(char *buf)
{
	int len;
	int i;
	int sharp;

	sharp = 0;
	i = 0;
	len = ft_strlen(buf);
	if ((len != 21) && (len != 20))
		return (0);
	while (buf[i] != '\0')
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (0);
		if (buf[i] == '#')
			sharp++;
		i++;
	}
	if (sharp != 4)
		return (0);
	if (!(check_tetriminos(buf, i)))
		return(0);
	return (1);
}

int	check_tetriminos(char *buf, int len)
{
	int com;
	int i;

	com = 0;
	i = 0;
	while (buf[i] != '\0')
	{
		if ((buf[i] == '#' && buf[i + 1] == '#') || (buf[i] == '#' && buf [i + 5] == '#') || (buf[i] == '#' && buf[i - 5] == '#'))
		{
			com ++;
		}
		i++;
	}
	printf("\nсвязи = %d\n",com);
	if (com  < 3)
		return (0);
	return (1);
}

t_list	*record(char *buf, t_list *point, char name)
{
	int i;
	t_list *new;

	new = point;    
	while (new)
	{
		new = new->next;
	}
	if (!new)
		new = ft_lstnew("", 1);
	ft_lstadd(&point, new);
 	i = ft_strlen(buf);
	buf[20] = name;
	buf[21]  = '\0';
	new->content = (char *)ft_strsub(buf, 0, i + i);
	return (new);
}