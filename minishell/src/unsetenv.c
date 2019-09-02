#include "includes/header.h"

void    ft_unsetenv(char **name)
{
    char    **new_env;
    unsigned int     index;
    unsigned int     jindex;

	index = 0;
    jindex = 0;
	if (name[1] == NULL || (!(new_env = (char **)malloc(sizeof(char *) * (SIZE_ENV + 1)))))
		return ;
    while (index < SIZE_ENV)
    {
        if (ft_strncmp(N_ENV[index], name[1], ft_strlen(name[1])) != 0)
        {
            new_env[jindex] = ft_strnew(ft_strlen(N_ENV[index]));
            ft_strcpy(new_env[jindex], N_ENV[index]);
           	jindex++;
        }
    index++;
    }
    SIZE_ENV = jindex;
    new_env[++jindex] = NULL;
    delete_char(N_ENV);
    N_ENV = new_env;
}