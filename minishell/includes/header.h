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
char			**n_env;
unsigned int	count_env;
/*
**	const
*/

#define TIL "~"
#define PATH "PATH="
#define ECHO "echo"
#define CD "cd"
#define SETENV "setenv"
#define UNSETENV "unsetenv"
#define ENV "env"
#define EXIT "exit"
#define HOME_DIR "/Users"
#define MAX_DIR 100
#define PREV_DIR "-"
#define PWD "PWD="
#define OLDPWD "OLDPWD="
#define NOTNEWLINE "-n"
#define SHLVL "SHLVL="
#define DOLL '$'

/*
**	File
*/

void	ft_exit(t_buff *buf);
void 	del_commas(char **str);

int		ft_pars(t_buff *buf);
void	loop(int argc, char **argv);
void	ft_container(t_buff *buf);
void	matr_print(char **str);// delete
void	rewrite_env();
int		inline_function(char **command);
void	delete_char(char **str);
/*
** cd 
*/
void	ft_cd(char **command);
int		ft_check_dir(char *str);
int		ft_cd_com(char **command, char *new_dir, char *current_dir, char *str);
void	ft_til(char *current_dir, char *new_dir, char *str, char **command);
void	ft_cd_way(char **command, char *current_dir, char *str, char *new_dir);
char	*pr_dir();
void	change_env(char *prev_dir);
char	*home_dir();

/*
** setenv
*/

void	ft_setenv(char **command);

void	ft_unsetenv(char *name);

#endif
