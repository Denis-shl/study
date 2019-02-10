#include "fillit.h"

int main(int argc, char **argv)
{
	int i;

	i = 0;
	t_list *point;
	t_list *new;
	int *che;

	point = ft_lstnew("", 1);
	if (argc != 2)
		return (0);
	if (!(new = check(argv, point)))
	{
		printf ("ERROR check_tetriminos %d\n",i);
		return (0);
	}
	if (!(record_name(point)))
	{
		printf("ERORr\n");
		return (0);
	}
	else 
		printf ("check passed");
	new = point;
	i = generic_map(point);
	point = point->next;
	printf ("point_content %s\n",point->content);
	point = ft_list(point, new, i);
	i = 0;
	while (new)
		{	
			che = (int *)point->content_size;
			while (i != 4)
			{
				printf ("%d\n",che[i]);
				i++;
			}
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

t_list	*ft_list(t_list *point, t_list *start, int i)
{
	int					**ar;
	int					j;
	int					*po;
	char				*str;
	
	po = NULL;
	start = point;
	ar = (int*)malloc(sizeof(int) * 4);
	while (point->next)
	{
		point->content_size = (size_t)ar;
		str = point->content;
	//	po = (int *)point->content_size;
		i = 0;
		j = 0; 
		while (str[i])
		{
			if (str[i] == '#')
			{
				ar[j] = i;
				j++;
			}
			i++;
		}
		point = point->next;
	}

	return (start);
}
