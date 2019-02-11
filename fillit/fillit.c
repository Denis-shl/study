#include "fillit.h"

int main(int argc, char **argv)
{
	int i;
	int siz;
	i = 0;
	t_list *point;
	t_list *new;
	char *map = NULL;

	siz = 0;
	point = ft_lstnew("", 1);
	if (argc != 2)
	{
		printf ("1");
		return (0);
	}
	if (!(new = check(argv, point, i, siz)))
	{
		printf ("2");
		return (0);
	}
	if (!(record_name(point)))
	{
		printf ("3");
		return (0);
	}
	else 
		printf ("check passed");
	//new = point; free
	i = generic_map(point);
	point = point->next;
	new = point;
	point = ft_list(point, new, siz);
	//i = 0;
	/*	int *g;
		while (new->next)
		{
			g = (int *)new->content_size;
			while (i != 4)
			{
				printf ("new->content_size = %d\n",g[i]);
				i++;
			}
			i = 0;
			new = new->next;
		}
		i = 0;
		g = (int *)new->content_size;
		while (i != 4)
			{
				printf ("new->content = %d\n",g[i]);
				i++;
			}*/
	map = ft_alco(point, 5);
	printf("map \n%s\n",map);

	
	
	
	return (0);
}

t_list	*ft_list(t_list *point, t_list *start, int siz)
{
	int					**ar;
	char				*str;
	int						i;
	while (point)
		{
			siz++;
			point = point->next;
		}
	ar = (int**)malloc(sizeof(int*) * siz);
	i = siz;
	siz = 0;
	point = start;
	while (i != siz)
	{
		if (!(ar[siz] = (int *)malloc(sizeof(int) * 4)))
			return (0);
		point->content_size = (size_t)ar[siz];
		str = point->content;
		ft_list_red(ar, str, siz);
		siz++;
		//printf ("set\n");
		if (point->next != NULL)
			point = point->next;
	}
	return (start);
}

void	ft_list_red(int **ar, char *str, int siz)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
		{
			if (str[i] == '#')
			{
				ar[siz][j] = i;
				j++;
			}
			i++;
		}
}
