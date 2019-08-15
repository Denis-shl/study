#include "includes/header.h"

static char	*home_dir()
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

static int	ft_check_dir(char *str)
{
	DIR			*dir;

	if (strcmp(TIL, str) == 0)
		return (1);
	dir = opendir(str);
	if (dir == NULL)
		return (0);
	else 
		closedir(dir);
	return (1);
}

void		ft_cd(char **command)
{
	char *home_d;
	char *str;

	if (command[1] == NULL || (strcmp(command[1], TIL) == 0))
	{
		if (!(home_d = home_dir()))
			home_d = HOME_DIR;
		chdir(home_d);
	}
	else 
	{
		if (!(ft_check_dir(command[1])))
		{
			printf ("cd: not a directory: %s\n", command[1]);
			return ;
		}
		home_d = ft_strjoin(getcwd(NULL, MAX_DIR), "/");
		str = home_d;
		home_d = ft_strjoin(home_d, command[1]);
		chdir(home_d);
		free(home_d);
		free(str);
	}
}
