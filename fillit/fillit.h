#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 10

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h> //////delete

int		main (int argc,char **argv);
t_list	*check(char **file, t_list *point, int i, int fd);
int		check_buf(char *buf, int i, int sharp, int point);
int		check_tetriminos(char *buf, int len);
t_list	*record(char *buf, t_list *point, char name);
int		record_name(t_list *point);
int		generic_map(t_list *point);
int		ft_sqrt(int nb);
t_list	*ft_list(t_list *point, t_list *start, int siz);
void	ft_list_red(int **ar, char *str, int siz);
int		ft_pos(char *map, int start);
int		check_for_fit(char *map,t_list *point);
char	*ft_insert(char *map, int *coor, char letter, int difference);
void	check_first(char *map, int size_map);
char	*ft_alco(t_list *point, int size_map);
int		ft_algorithm(t_list *point, char *map, int pos, char name);
int		*ft_difference(int *cor, int pos,char *map, int len);
#endif