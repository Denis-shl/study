#include "../includes/minishell.h"

void			matr_print(char **str)
{
	for (int i = 0; str[i]; i++)
	{
		ft_printf("{%d}{%s}\n", i, str[i]);
	}
}