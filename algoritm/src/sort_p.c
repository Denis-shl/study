// #include ""
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_puz(int *mas, int size)
{
	int pos;
	int start;
	int swap;

	pos = 0;
	start = 0;
	swap = 0;
	while (start < size)
	{
		pos++;
		while (pos < size)
		{
			/*swap*/
			if (mas[pos - 1] > mas[pos] && pos != size)
			{
				swap = mas[pos];
				mas[pos] = mas[pos - 1];
				mas[pos - 1] = swap;
			}
			pos++;
			
		}
		pos = 0;
		start++;
	}
}

int main ()
{
	int *mas;
	int index;

	index = 0;
	mas = (int *)malloc(sizeof(int) * 10);
	if (!mas)
		return (-1);
	while (index < 10)
	{
		mas[index] = 9 - index;
		index++;
	}
	for(int i = 0; i < 9; i++)
	printf ("%d ", mas[i]);
	sort_puz(mas, 9);
	for(int i = 0; i < 9; i++)
	printf ("\n%d ", mas[i]);
	return (0);
}