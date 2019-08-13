# ifndef HEADER_H
# define HEADER_H
#include "../../libft/includes/libft.h"
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h> /* delete */


/*
**	Macross
*/
#define EXIT "exit"
#define PATH "PATH="


/*
**	File
*/

void	ft_pars(t_buff *buf, char **env);
void	loop(int argc, char **argv, char **env);
int		ft_container(t_buff *buf, char **env);
void	ft_exit();
void	matr_print(char **str);// delete
char	**rewrite_env(char **env);
char	*finding_ways(char *name, char **env);
#endif
