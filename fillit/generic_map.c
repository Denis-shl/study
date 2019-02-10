#include "fillit.h"

int generic_map(t_list *point)
{
	int index;

	index = 0;
	while (point)
	{
		if ((point = point->next))
			index++;
	}
	printf("\nsqrt = %d\n index - %d\n",ft_sqrt(index * 4), index);
	return (0);
}

int		ft_sqrt(int nb)
{
	int i;

	i = 2;
	if (nb == 0)
		return (1);
	while (i < nb / (i - 1))
	{
		if (((i * i) == nb) || ((i * i) + 1 >= nb))
		{
			return (i);
		}
		i++;
	}
	return (i);
}
