#include "includes/header.h"

char	*home_dir()
{
	int				index;
	char 			*home;

	index = 0;
	home = NULL;
	while (n_env[index] != NULL)
	{
		if (((home = strstr(n_env[index], "HOME=/")) != NULL))
		{
			home = home + 5;
			return (home);
		}
		index++;
	}
	return (NULL);
}

void ft_til(char *current_dir, char *new_dir, char *str, char **command)
{
	if (!(new_dir = home_dir()))
		new_dir = HOME_DIR;
	str = ft_strcpy(ft_strnew(ft_strlen(command[1])), command[1]);
	str++;
	free(command[1]);
	command[1] = ft_strnew(ft_strlen(new_dir) + ft_strlen(str) + 1);
	strcpy(command[1], new_dir);
	command[1] = ft_strcat(command[1], str);
	chdir(command[1]);
	change_env(current_dir);
	free(--str);
	return ;
}

int	ft_check_dir(char *str)
{
	DIR			*dir;

	if (strcmp(PREV_DIR, str) == 0)
		return (2);
	dir = opendir(str);
	if (dir == NULL)
		return (0);
	else 
		closedir(dir);
	return (1);
}

int		ft_cd_com(char **command, char *new_dir, char *current_dir, char *str)
{
	if (command[1] == NULL)
	{
		if (!(new_dir = home_dir()))
			new_dir = HOME_DIR;
		chdir(new_dir);
		change_env(current_dir);
		return (0);
	}
	if (command[1][0] == '~')
	{
		ft_til(current_dir, new_dir, str, command);
		return (0);
	}
	if (command[1][0] == '/' && command[1][1] == '\0')
	{
		chdir("/");
		change_env(current_dir);
		return (0);
	}
	return (1);
}

void		ft_cd(char **command)
{
	char *new_dir;
	char *str;
	char *current_dir;
	int flag;

	flag = 0;
	current_dir = getcwd(NULL, MAX_DIR);
	if (ft_cd_com(command, new_dir, current_dir, str) == 0)
		return ;

	if (ft_check_dir(command[1]) == 0)
	{
		printf ("cd: not a directory: %s\n", command[1]);
		return ;
	}
	ft_cd_way(command, current_dir, str, new_dir);
	free(current_dir);
}