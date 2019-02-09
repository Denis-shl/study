#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 10

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h> //////delete 

int	main (int argc,char **argv);
t_list	*check(char **file, t_list *point);
int	check_buf(char *buf);
int	check_tetriminos(char *buf, int len);
t_list	*record(char *buf, t_list *point, char name);

#endif