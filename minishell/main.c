#include "includes/header.h"

#define  EXIT "exit"



/*
**	signal Control + D
*/



void ft_exit()
{
	exit(0);
}

char **rewrite_env(char **env)
{
	char **n_env;
	int size_en = 0;
	int i = 0;
	int size = 0;
	int j;

	size_en = 0;
	i = 0;
	while (env[size_en])
		size_en++;
	if (!(n_env = (char **)malloc(sizeof(char *) * (size_en + 1))))
		ft_exit();
	size_en = 0;
	while (env[i] != NULL)
	{
		size = ft_strlen(env[size_en]);
		if (!(n_env[i] = (char *)malloc(sizeof(char) * (size + 1))))
			ft_exit();
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
	return (n_env);
}



/*
**	сбор функций 
*/
int ft_container(t_buff *buf, char **env)
{
	char **n_env;
	n_env = rewrite_env(env);
	ft_pars(buf, n_env);
	return (1);
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
			ft_buffaddsymb(buf, sub);
		}
		if (strstr(buf->str, EXIT) != NULL)
			ft_exit ();
		if (i == 0)
			ft_exit();
		// printf ("%s", buf->str);// test buf->str;
		if (!(ft_container(buf, env)))
			continue ;
		ft_buffdel(&buf);

	}
}

int main (int argc, char **argv, char **env)
{
	loop (argc, argv, env);
	return (0);
}
