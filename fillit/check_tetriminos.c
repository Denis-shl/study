#include "fillit.h"

int	check_tetriminos(char **file, t_list *point)
{
	int fd;
	size_t i;
	char *buf[10];

	if (!(fd = open(file[1], O_RDONLY)))
		return (0);
	while (i = read(fd, buf, 10))
	{
		
	}
	close (fd);
	return (1);
}