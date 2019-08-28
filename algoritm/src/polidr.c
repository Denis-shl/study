#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
	char str[] = "tottot";
	int index;
	int size;
	int jindex; 
	int polidr;
	int max_polidr;

	polidr = 0;
	max_polidr = 0;
	index = 0;
	size = strlen(str);
	jindex = size - 1;

	while (index < jindex)
	{
		if (str[index] == str[jindex])
			polidr++;
		else if (polidr > max_polidr)
			max_polidr = polidr;
		index++;
		jindex--;
	}
	if (polidr > max_polidr)
			max_polidr = polidr;

	printf ("%d\n", max_polidr);
	return (0);
}