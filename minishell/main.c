#include "includes/header.h"

#define  EXIT "exit"



/*
**	signal Control + D
*/



void ft_exit(t_buff *buf)
{
	if (buf && buf->str != NULL)
	{
		ft_buffdel(&buf);
	}
	exit(0);
}

void rewrite_env(char **env)
{
	int size_en;
	int i ;
	int size;
	int j;

	size_en = 0;
	i = 0;
	while (env[size_en])
		size_en++;
	if (!(n_env = (char **)malloc(sizeof(char *) * (size_en + 1))))
		ft_exit(NULL);
	size_en = 0;
	while (env[i] != NULL)
	{
		size = ft_strlen(env[size_en]);
		if (!(n_env[i] = (char *)malloc(sizeof(char) * (size + 1))))
			ft_exit(NULL);
		j = 0;
		while (env[i][j] != '\0')
		{
			n_env[i][j] = env[i][j];
			j++;
		}
		n_env[i][j] = '\0';
		i++;
		size_en++;
	}
}



/*
**	сбор функций 
*/
void ft_container(t_buff *buf, char **env)
{
	rewrite_env(env);
	if (ft_pars(buf) == 0)
	{
		printf("ERROR : %s",buf->str);
		return ;
	}
	return ;
}

void loop(int argc, char **argv, char **env)
{
	t_buff *buf;
	char sub;
	int i;

	while (1)
	{
		buf = ft_buffinit(1000);
		write (1, "minishell ", 10);
		while ((i = (read(0, &sub, 1))))
		{
			if (sub == '\n')
				break ;
			if (i == 0)
				ft_exit(buf);
			ft_buffaddsymb(buf, sub);
		}
		ft_container(buf, env);
		ft_buffdel(&buf);
		
	}
}

int main (int argc, char **argv,char **env)
{
	loop (argc, argv, env);
	return (0);
}
