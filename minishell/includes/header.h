/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:00:17 by oargrave          #+#    #+#             */
/*   Updated: 2019/09/03 16:59:03 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "../../libft/includes/libft.h"
# include <sys/types.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>
# include "../../libft/ft_printf/includes/header.h"

/*
**		Global variables
*/
char			**g_env;
unsigned int	g_size_env;
/*
**	const
*/

# define TIL "~"
# define PATH "PATH="
# define ECHO "echo"
# define CD "cd"
# define SETENV "setenv"
# define UNSETENV "unsetenv"
# define ENV "env"
# define EXIT "exit"
# define HOME_DIR "/Users"
# define PREV_DIR "-"
# define PWD "PWD="
# define OLDPWD "OLDPWD="
# define NOTNEWLINE "-n"
# define SHLVL "SHLVL="
# define DOLL '$'

/*
** size const variables example: (unsetenv)| (~)
**								 (12345678)| (1)
*/

# define SIZE_TIL 1
# define SIZE_PATH 5
# define SIZE_ECHO 4
# define SIZE_CD 2
# define SIZE_SETENV 6
# define SIZE_UNSETENV 8
# define G_SIZE_ENV_NAME 3
# define SIZE_EXIT 4
# define SIZE_HOME_DIR 6
# define SIZE_PREV_DIR 1
# define SIZE_PWD 4
# define SIZE_OLDPWD 7
# define SIZE_NOTNEWLINE 2
# define SIZE_SHLVL 6
# define SIZE_DOLL 1
# define MAX_DIR 256

/*
**	File
*/

void	ft_exit(t_buff *buf);
void	ft_shlvl(char *str);
void	del_commas(char **str);
int		launch_shell(char **args);
char	*ft_search(char *str);
char	*clean_way(char **str, char *name);

int		ft_pars(t_buff *buf);
void	loop(int argc, char **argv);
void	ft_container(t_buff *buf);
void	matr_print(char **str);
void	rewrite_env();
int		inline_function(char **command);
void	delete_char(char **str);
/*
** cd  and til and env
*/
void	ft_cd(char **command);
int		ft_check_dir(char *str);
int		ft_cd_com(char **command, char *new_dir, char *current_dir, char *str);
void	ft_til(char *current_dir, char *new_dir, char *str, char **command);
void	ft_cd_way(char **command, char *current_dir, char *str, char *new_dir);
char	*pr_dir();
void	change_env(char *prev_dir);
char	*home_dir();


void	ft_echo(char **str);
/*
** setenv and unsetenv
*/
void	ft_setenv(char **command);
void	ft_unsetenv(char **name);
/*
** delete
*/
void	matr_print(char **str);
#endif
