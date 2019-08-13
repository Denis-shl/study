#include "includes/header.h"

void matr_print(char **str)
{
	for (int i = 0; str[i]; i++)
		printf ("{%s}\n", str[i]);
}

void delete_char(char **str)
{
	int index;

	index = 0;
	while (str[index] != NULL)
		index++;
	while (index != 0)
	{
		index--;
		free(str[index]);
	}
	free(str);
	str = NULL;
}

char *clean_way(char **str, char *name)
{
	int index;
	char *way;

	index = 0 ;
	way = 0;

	while (str[index] != NULL)
	{
		str[index] = ft_strjoin(str[index], "/"); //liks
		way = ft_strjoin(str[index], name);
		if (access(way, 0) == 0)
			return (way);
		index++;
		free(way);
	}
	return (NULL);
}

char *finding_ways(char *name, char **env)
{
	char *way;
	char *str;
	char **all_the_way;
	int in_env;
	
	str = NULL;
	in_env = 0;
	while(env[in_env])
	{
		if ((way = strstr(env[in_env], PATH)) != NULL)
		{
			str = ft_strcpy(ft_strnew(ft_strlen(way) - 5), way + 5);
			free(way);
		}
		in_env++;
	}
	all_the_way = ft_strsplit(str, ':');
	way = clean_way(all_the_way, name);
	free(str);
	delete_char(all_the_way); // refactoring delete **
	return (way);
}

/*
**Новый процесс
*/
int ft_launch(char **args, char **env)
{
	pid_t pid, wpid;
	int status;
	char *way;

	way = finding_ways(args[0], env);
	pid = fork();
	if (pid == 0)
		execve(way, args, env);
	else 
	     wpid = wait(&status);
  return (0);
}

/*
**	парсим сначала по ; потом по пробелу
*/
void ft_pars(t_buff *buf, char **env)
{
	char **str;
	char **command = NULL;
	int i;

	i = 0;
	str = ft_strsplit(buf->str, ';');
	while (str[i])
	{
		command = ft_strsplit(str[i], ' ');
		ft_launch(command, env);
		delete_char(command);
		command = NULL;
		i++;
	}
	delete_char(str);
}