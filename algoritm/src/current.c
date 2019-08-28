#include <stdio.h>
#include <stdlib.h>

int ft_cur(const int i)
{
	unsigned int num;

	num = 1;
	if (i <= 0)
		return (0);
	while (1)
	{
		if (num == i)
			return (1);
		else if (num > i)
			return (0);
		num = num << 1;
		// printf ("%d\n", num);
	}

}

int main ()
{
	int a = -512;
	int b = 512;
	int c = 513;

	printf ("%d\n",ft_cur(a));
	printf ("%d\n",ft_cur(b));
	printf ("%d\n",ft_cur(c));
	return (0);
}