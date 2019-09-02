#include "includes/header.h"


void change_env(char *prev_dir)
{
	int index;
	char *current_dir;

	current_dir = getcwd(NULL, MAX_DIR);
	index = 0;
	while (N_ENV[index] != NULL)
	{
		if (ft_strnstr(N_ENV[index], PWD, 5) != NULL)
		{
			free(N_ENV[index]);
			N_ENV[index] = ft_strnew(MAX_DIR);
			strcpy(N_ENV[index], PWD);
			N_ENV[index] = ft_strcat(N_ENV[index], current_dir);
		}
		if (ft_strnstr(N_ENV[index], OLDPWD, 8) != NULL)
		{
			free(N_ENV[index]);
			N_ENV[index] = ft_strnew(MAX_DIR);
			strcpy(N_ENV[index], OLDPWD);
			N_ENV[index] = ft_strcat(N_ENV[index], prev_dir);
		}
		index++;
	}
}

char *pr_dir()
{
	char *new_dir;
	int index;

	index = 0;
	while (N_ENV[index] != NULL)
	{
		if ((new_dir = ft_strnstr(N_ENV[index], OLDPWD, 8)) != NULL)
		 return (new_dir + 7);
		index++; 
	}
	return (new_dir);
}

void ft_cd_way(char **command, char *current_dir, char *str, char *new_dir)
{
	if (ft_check_dir(command[1]) == 1)
	{
		new_dir = ft_strjoin(current_dir, "/");
		str = new_dir;
		new_dir = ft_strjoin(new_dir, command[1]);
		chdir(new_dir);
		change_env(current_dir);
		free(new_dir);
		free(str);
	}
	else
	{
		new_dir = pr_dir();
		chdir(new_dir);
		change_env(current_dir);
		new_dir = getcwd(NULL, MAX_DIR);
		printf ("%s\n", new_dir);
		free(new_dir);
	}
}


