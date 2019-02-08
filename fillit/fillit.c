#include "fillit.h"

int main(int argc, char **argv)
{
	int i;
	t_list *point;
	if (argc != 2)
		return (0);
	if (!(check_tetriminos(argv, point)))
		return (0);
	return (0);
}
