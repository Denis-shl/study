#include "includes/header.h"
#include "../libft/includes/libft.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h> /* delete */

void loop(int argc, char **argv, char **env)
{
	t_buff *buf;
	int i = 0;

	buf = ft_buffinit(10);	
	while (1)
	{
		write (1, "mishell\n", 3);
		while (read(0, buf->str, 1))
		{
			if (buf->str[i] == '\n')
				break ;
			printf ("%s", buf->str);
		}
	}
}

int main (int argc, char **argv, char **env)
{
	loop (argc, argv, env);
	return (0);
}
