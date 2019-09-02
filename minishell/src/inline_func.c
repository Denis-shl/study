#include "includes/header.h"

void ft_env()
{
	int index;

	index = 0;
	while (N_ENV[index] != NULL)
	{
		printf("%s\n", N_ENV[index]);
		index++;
	}
}
void 	del_commas(char **str)
{
	int index;
	int jindex;

	index = 0;

	while (str[index] != NULL)
	{
		jindex = 0;
		while (str[index][jindex] != '\0')
		{
			if (str[index][jindex] == '"')
				str[index][jindex] = 1;
			jindex++;
		}
		index++;
	}
}

void ft_echo(char **str)
{
	int index;

	index = 1;
	del_commas(str);
	if (str[1] != NULL && ft_strcmp(str[1], NOTNEWLINE) == 0)
		return ;
	while (str[index] != NULL)
	{
		write(1, str[index], ft_strlen(str[index]));
		write(1, " ", 1);
		index++;
	}
	ft_putchar('\n');
}


char *ft_search(char *str)
{
	int index;
	char *command;
	char **tmp;

	index = 0;
	while (N_ENV[index] != NULL)
	{
		if (ft_strncmp(N_ENV[index], str, ft_strlen(str)) == 0)
		{
			tmp = ft_strsplit(N_ENV[index], '=');
			command = ft_strdup(tmp[1]);
			delete_char(tmp);
			printf ("%s\n", command);
			return (command);
		}
		index++;
	}	
	return (NULL);
}
int ft_dollar(char **command)
{
	int index;
	char *str;
	char *com;
	char **new_command;
	char *line;

	
	com = NULL;
	line = command[0];
	index = 0;
	str = ft_strdup(line + 1);
	com = ft_search(str);
	if (com != NULL)
	{
		new_command = (char **)malloc(sizeof(char) * 2);
		new_command[0] = com;
		new_command[1] = NULL;
		if ((inline_function(new_command) == 0))
			launch_shell(new_command);
	}
	else
		printf ("%s: Uwndefined variable.\n",str);
	return (0);
}

int inline_function(char **command)
{
	int index;
	
	index = 0; 
	if(ft_strncmp(command[0], ECHO, SIZE_ECHO) == 0)
		ft_echo(command);
	else if(ft_strncmp(command[0], CD, SIZE_CD) == 0)
		ft_cd(command);
	else if(ft_strncmp(command[0], SETENV, SIZE_SETENV) == 0)
		ft_setenv(command);
	else if(ft_strncmp(command[0], UNSETENV, SIZE_UNSETENV) == 0)
		ft_unsetenv(command);
	else if(ft_strncmp(command[0], ENV, SIZE_ENV_NAME) == 0)
		ft_env();
	else if (command[0][0] == DOLL)
		ft_dollar(command);
	else if(ft_strncmp(command[0], EXIT, SIZE_EXIT) == 0)
		return (-1);
	else return (0);

	return (1);
}