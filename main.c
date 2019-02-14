#include <stdio.h>
#include <stdlib.h>

char *check_ls(char **point)
{
	point[0][0] = 'a';
	return (point[0]);

}


int main ()
{
	char *point;
	char *mas;

	point = (char*)malloc(sizeof(char) * 10);
	mas = check_ls(&point);
	printf ("point %s",mas);
	return (0);
}
