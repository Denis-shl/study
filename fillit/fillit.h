#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 10

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h> //////delete 

int	main (int argc,char **argv);
int	check_tetriminos(char **file, t_list *point);

#endif