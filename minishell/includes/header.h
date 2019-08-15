# ifndef HEADER_H
# define HEADER_H
#include "../../libft/includes/libft.h"
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h> /* delete */
#include <sys/stat.h>
#include <dirent.h>

/*
**		Global variables
*/
char **n_env;

/*
**	const
*/

#define TIL "~"
#define PATH "PATH="
#define ECHO "echo"
#define CD "cd"
#define SETENV "setenv"
#define UNSETNV "unsetnv"
#define ENV "env"
#define EXIT "exit"
#define HOME_DIR "/Users"
#define MAX_DIR 100

/*
**	File
*/

void	ft_exit(t_buff *buf);

int		ft_pars(t_buff *buf);
void	loop(int argc, char **argv, char **env);
void	ft_container(t_buff *buf, char **env);
void	matr_print(char **str);// delete
void	rewrite_env();
int		inline_function(char **command);
void 	ft_cd(char **command);

#endif
