#include "includes/header.h"

void    ft_unsetenv(char **name)
{
    char    **new_env;
    int     index;
    int     jindex;

    index = 0;
    jindex = 0;
    if (name == NULL)
        return ;
    if (!(new_env = (char **)malloc(sizeof(char *) * count_env + 1)))
        return ;
    while (index < count_env)
    {
        if (ft_strncmp(n_env[index], name[1], ft_strlen(name[1])) == 0)
        {
            new_env[jindex] = ft_strnew(ft_strlen(n_env[index]));
            ft_strcpy(new_env[jindex], n_env[index]);
           	jindex++;
        }
    index++;
    }
    count_env = jindex;
    new_env[++jindex] = NULL;
    delete_char(n_env);
    n_env = new_env;
}