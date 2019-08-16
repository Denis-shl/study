#include "includes/header.h"


void change_env(char *prev_dir)
{
	int index;
	char *current_dir;

	current_dir = getcwd(NULL, MAX_DIR);

	index = 0;
	while (n_env[index] != NULL)
	{
		if (ft_strnstr(n_env[index], PWD, 5) != NULL)
		{
			free(n_env[index]);
			n_env[index] = ft_strnew(MAX_DIR);
			strcpy(n_env[index], PWD);
			n_env[index] = ft_strcat(n_env[index], current_dir);
		}
		if (ft_strnstr(n_env[index], OLDPWD, 8) != NULL)
		{
			free(n_env[index]);
			n_env[index] = ft_strnew(MAX_DIR);
			strcpy(n_env[index], OLDPWD);
			n_env[index] = ft_strcat(n_env[index], prev_dir);
		}
		index++;
	}
}

char *pr_dir()
{
	char *new_dir;
	int index;

	index = 0;
	while (n_env[index] != NULL)
	{
		if ((new_dir = ft_strnstr(n_env[index], OLDPWD, 8)) != NULL)
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


