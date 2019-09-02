#include "../includes/header.h"

void			matr_print(char **str)
{
	for (int i = 0; str[i]; i++)
	{
		printf("{%d}{%s}\n", i, str[i]);
	}
}