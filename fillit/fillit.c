#include "fillit.h"

int main(int argc, char **argv)
{
	int i;
	t_list *point;
	if (argc != 2)
		return (0);
	if (!(point = check(argv, point)))
	{
		printf ("ERROR check_tetriminos %d\n",i);
		return (0);
	}
	else 
		printf ("check passed");
		
	while ((point->next))
		{
			printf ("\n%s\n",point->content);
			point = point->next;
		}
		
	return (0);
}
