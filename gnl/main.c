#include "get_next_line.h"

t_list *ft_file_check(t_list **file, int fd)
{
	t_list *point;

	point = *file;
	while (point)
	{
		if (point->content_size == fd)
			return (point);
		point = point->next;
	}
	if (!point)
		point = ft_lstnew("",fd);
	ft_lstadd(file, point);
	point = *file; 
	return (point);
}

int get_next_line (const int fd, char **line)
{
	int i;
	char *buf;
	static t_list *file;
	t_list *point;

	buf = NULL;
	if (!fd)
	   return (0);
	buf = ft_memalloc(10);	
	point = ft_file_check(&file, fd);
	while ((i = read(fd, buf, 10)))
	{
		buf[i] = '\0';
	}



	return (1);
}


int main(int argc, char **argv)
{
	int fd;
	char *line;
	int flag = O_RDONLY;

	line = NULL;
	if (!(fd = open(argv[1],flag)))
		return (0);
	if (!(get_next_line(fd,&line)))
		printf("ERROR");
	return (0);
}
