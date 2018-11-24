#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>
int main ()
{
	char mas[] = "Hello World denis";
	char str[] = "Hello World denis";
	char *point1 = mas;
	char *point2 = str;
	bzero(point1,18);
	printf ("%s\n",mas);
	ft_bzero(point2,3);
	printf("%s\n",str);
	return (0);
}
