#include "includes/header.h"

void ft_env_new_line(char *name, char *argv)
{
	char **new_env;
	int index;
	char *tmp;
	
	index = 0;
	if (!(new_env = (char **)malloc(sizeof(char *) * (count_env + 2))))
		return ;
	while (n_env[index] != NULL)
	{
		new_env[index] = ft_strnew(ft_strlen(n_env[index]));
		ft_strcpy(new_env[index], n_env[index]);
		index++;
	}
	new_env[index] = ft_strjoin(name, "=");
	if (argv != NULL)
	{
		tmp = new_env[index]; 
		new_env[index] = ft_strjoin(new_env[index], argv);
		free(tmp);
	}
	count_env = index;
	new_env[index + 1] = NULL;
	delete_char(n_env);
	n_env = new_env;
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

	if (command[3] != NULL )
	{
		printf ("setenv: Too many arguments.\n");
		return ;
	}
	if (check_name_setenv(command[1]) == -1)
	{
		printf("setenv: Variable name must begin with a letter.\n");
		return ;
	}
	while (n_env[index] != NULL)
	{
		if (ft_strncmp(n_env[index], command[1], ft_strlen(command[1])) == 0)
		{
			n_env[index] = ft_read_set(command[2], n_env[index], command[1]);
			return ;
		}
		index++;
	}
	ft_env_new_line(command[1], command[2]);
}
