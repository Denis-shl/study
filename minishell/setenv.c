#include "includes/header.h"

void ft_env_new_line(char *name, char *argv)
{
	char *tmp;
	char **new_env;
	int index;

	index = 0;
	if (!(new_env = (char **)malloc(sizeof(char *) * count_env + 2)))
		return ;
	while (index < count_env)
	{
		new_env[index] = ft_strnew(ft_strlen(n_env[index]));
		ft_strcpy(new_env[index], n_env[index]);
		index++;
	}
	new_env[index] = ft_strjoin(name, "=");
	tmp = new_env[index];
	if (argv != NULL)
	{
		new_env[index] = ft_strjoin(new_env[index], argv);
		free(tmp);
	}
	count_env = index;
	new_env[++index] = NULL;
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

void ft_setenv(char **command)
{
	int index;

	index = 0;
	while (n_env[index] != NULL)
	{
		if (strstr(n_env[index], command[1]) != NULL)
		{
			n_env[index] = ft_read_set(command[2], n_env[index], command[1]);
			return ;
		}
		index++;
	}
	if (n_env[index] == NULL)
		ft_env_new_line(command[1], command[2]);
}
