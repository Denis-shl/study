#include "includes/header.h"

void ft_env_new_line(char *name, char *argv)
{
	char **new_env;
	int index;
	char *tmp;
	
	index = 0;
	if (!(new_env = (char **)malloc(sizeof(char *) * (SIZE_ENV + 2))))
		return ;
	while (N_ENV[index] != NULL)
	{
		new_env[index] = ft_strnew(ft_strlen(N_ENV[index]));
		ft_strcpy(new_env[index], N_ENV[index]);
		index++;
	}
	new_env[index] = ft_strjoin(name, "=");
	if (argv != NULL)
	{
		tmp = new_env[index]; 
		new_env[index] = ft_strjoin(new_env[index], argv);
		free(tmp);
	}
	SIZE_ENV = index;
	new_env[index + 1] = NULL;
	delete_char(N_ENV);
	N_ENV = new_env;
}

char *ft_read_set(char *arg, char *str, char *name)
{
	char *tmp;

	free(str);
	str = ft_strjoin(name, "=");
	tmp = str;
	if (arg != NULL)
	{
		str = ft_strjoin(str, arg);
		free(tmp);
	}
	return (str); 
}

int check_name_setenv(char *name)
{
	int index;
	int size;

	index = 1;
	size = ft_strlen(name);
	if (name[0] >= 48 && name[0] <= 57)
			return (-1);
	while (index < size)
	{
		if (name[index] >= 65 && name[index] <= 90)
			 ;
		else if (name[index] >= 97 && name[index] <= 122)
			 ;
		else if (name[index] == 95)
			 ;
		else
			return (-1);
		index++;
	}
	return (0);
}
void ft_setenv(char **command)
{
	int index;
	index = 0;

	if (command[2] != NULL && command[3] != NULL )
	{
		printf ("setenv: Too many arguments.\n");
		return ;
	}
	if (check_name_setenv(command[1]) == -1)
	{
		printf("setenv: Variable name must begin with a letter.\n");
		return ;
	}
	while (N_ENV[index] != NULL)
	{
		if (ft_strncmp(N_ENV[index], command[1], ft_strlen(command[1])) == 0)
		{
			N_ENV[index] = ft_read_set(command[2], N_ENV[index], command[1]);
			return ;
		}
		index++;
	}
	ft_env_new_line(command[1], command[2]);
}
