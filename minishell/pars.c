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
	if (!str)
		return ;
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

static char *clean_way(char **str, char *name)
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

static char *finding_ways(char *name)
{
	char *way;
	char *str;
	char **all_the_way;
	int in_env;
	
	str = NULL;
	in_env = 0;
	while(n_env[in_env])
	{
		if ((way = strstr(n_env[in_env], PATH)) != NULL)
		{
			str = ft_strcpy(ft_strnew(ft_strlen(way) - 5), way + 5);
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
static int launch_shell(char **args)
{
	pid_t pid, wpid;
	int status;
	char *way;

	if (!(way = finding_ways(args[0])))
		return (0);
	printf ("HELLO2 ");
	pid = fork();
	if (pid == 0)
		execve(way, args, n_env);
	else 
	     wpid = wait(&status);
  return (1);
}

/*
**	парсим сначала по ; потом по пробелу
*/
int ft_pars(t_buff *buf)
{
	char **str;
	char **command = NULL;
	int i;
	int flag;

	i = 0;
	str = ft_strsplit(buf->str, ';');
	while (str[i])
	{
		command = ft_strsplit(str[i], ' ');
		if ((flag = inline_function(command)) == 1)
			return (0);
		else if (flag == -1)
		{
			delete_char(command);
			delete_char(str);
			exit (0);
		}
		else
			launch_shell(command);	
		delete_char(command);
		command = NULL;
		i++;
	}
	delete_char(str);
	return (1);
}