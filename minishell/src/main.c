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

void ft_rouding(char *str)
{

}

void ft_shlvl(char *str)
{
	int index;
	char *tmp;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] >= 48 && str[index] < 57 && str[index + 1] == '\0')
			str[index]++;
		index++;
	}

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
	SIZE_ENV = size_en;
	if (!(N_ENV = (char **)malloc(sizeof(char *) * (size_en + 1))))
		ft_exit(NULL);
	size_en = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], SHLVL, ft_strlen(SHLVL)) == 0)
			ft_shlvl(env[i]);
		size = ft_strlen(env[size_en]);
		if (!(N_ENV[i] = (char *)malloc(sizeof(char) * (size + 1))))
			ft_exit(NULL);
		j = 0;
		while (env[i][j] != '\0')
		{
			N_ENV[i][j] = env[i][j];
			j++;
		}
		N_ENV[i][j] = '\0';
		i++;
		size_en++;
	}
}



/*
**	сбор функций 
*/
void ft_container(t_buff *buf)
{
	if (ft_pars(buf) == 0)
	{
		return ;
	}
	return ;
}

void loop(int argc, char **argv)
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
		ft_container(buf);
		ft_buffdel(&buf);
	}
}

int main (int argc, char **argv,char **env)
{
	rewrite_env(env);
	loop (argc, argv);
	return (0);
}
