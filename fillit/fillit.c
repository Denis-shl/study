#include "fillit.h"

int main(int argc, char **argv)
{
	int i;

	i = 0;
	t_list *point;
	t_list *new;

	//int *ar;

	//ar = (int*)malloc(sizeof(int) * 10);

	point = ft_lstnew("", 1);
	if (argc != 2)
		return (0);
	if (!(new = check(argv, point)))
	{
		printf ("ERROR check_tetriminos %d\n",i);
		return (0);
	}
	/*if (!(record_name(point)))
	{
		printf("ERORr\n");
		return (0);
	}*/
	else 
		printf ("check passed");
	new = point;
	 i = generic_map(point);
	while (new)
		{
			printf ("\n%s\n",new->content);
			new = new->next;
		}
	
	/*ar[0] = 1;
	ar[1] = 2;
	ar[9] = 200500;
	//int *x;*/
	//point->content_size = (size_t)ar;
	//x = (int *)point->content_size;
//	printf("content_size = %d", x[0]);
	return (0);
}
