#include "includes/header.h"

void ft_env()
{
	int index;

	index = 0;
	while (n_env[index] != NULL)
	{
		printf("%s\n", n_env[index]);
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

int inline_function(char **command)
{
	int index;
	
	index = 0;
	if(strstr(command[0], ECHO) != NULL)
		ft_echo(command);
	else if(strstr(command[0], CD) != NULL)
		ft_cd(command);
	else if(strstr(command[0], SETENV) != NULL)
		ft_setenv(command);
	else if(strstr(command[0], UNSETENV) != NULL)
		ft_unsetenv(command[1]);
	else if(strstr(command[0], ENV) != NULL)
		ft_env();
	else if(strstr(command[0], EXIT) != NULL)
		return (-1);
	else return (0);

	return (1);
}