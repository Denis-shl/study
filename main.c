/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:54:29 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/24 23:32:58 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int 	ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memccpy(void *dst,const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b,int c, size_t n );
char	*ft_strcat(char *s1, const char *s2);
int main()
{
	char mas1 [] = "Hello world";
	char mas2 [] = "Hello world";
	bzero(mas1,6);
	ft_bzero(mas2,6);
	printf("bzero = %s \n",mas1);
	printf("ft_bzero = %s \n",mas2);
	///////////////////////////////////////////////
	char a = 'A';
	char b = '~';
	printf ("isalnum = %d \n",isalnum((int) a));
	printf ("ft_isalnum = %d \n",ft_isalnum((int) a));
	///////////////////
	printf ("isalpha = %d \n",isalpha(b));
	printf ("ft_isalpha = %d \n",ft_isalpha(b));
	////////
	printf("isascii = %d \n",isascii(b));
	printf("ft_isascii = %d \n",ft_isascii(127));
	///////
	printf("isdigit = %d \n",isdigit('3'));
	printf("ft_isdigit = %d \n",ft_isdigit('3'));
	////////////////////
	printf("isprint = %d \n",isprint('D'));
	printf("ft_isprint = %d \n",ft_isprint('d'));
	printf("____________________________________________________________\n");
	char mas3[] = "                               ";
	char mas4[] = "Hello_world!";
	char mas5[] = "                               ";
	char mas6[] = "Hello_world!";

	char *point1;
	char *point2;
	point1 = memccpy(mas3,mas4,'e',3);
	point2 = ft_memccpy(mas5,mas6,'e',3);
	printf("memccpy = %s\n",point1 - 2);
	printf ("ft_memccpy = %s\n",point2 - 2);
	printf("_____________________________________\n");
	point1 = memchr(mas4,'e',3);
	point2 = ft_memchr(mas6,'e',3);
	printf("memchr = %c \n",*point1);
	printf("ft_memchr = %c \n",*point2);
	printf ("________________________________________\n");
	printf ("memcmp = %d \n",memcmp(mas4,mas6,6));
	printf ("ft_memcmp = %d \n",ft_memcmp(mas4,mas6,6));
	printf("__________________________________________________________\n");
	point1 = memcpy(mas3,mas4,12);
	point2 = ft_memcpy(mas5,mas6,12);
	printf ("   memcpy = %s\n",point1);
	printf ("ft_memcpy = %s\n",point2);
	printf ("___________________________________________________________\n");
	point1 = memmove(mas3,mas4,12);
	point2 = ft_memmove(mas5,mas6,12);
	printf ("   memmove = %s\n",point1);
	printf ("ft_memmove = %s\n",point2);
	printf ("_______________________________________________________________\n");
	point1 = memset (mas3,'Z',12);
	point2 = ft_memset(mas5,'z',12);
	printf ("   memset = %s\n",point1);
	printf ("ft_memset = %s\n",point2);
	printf("__________________________________________________________________\n");
	char mas7[] = "\0                               ";
	char mas8[] = "Hello_world!";
	char mas9[] = "\0                               ";
	char mas10[] = "Hello_world!";

	point1 = strcat(mas7,mas8);
	point2 = ft_strcat(mas9,mas10);
	printf ("   strcat = %s\n",point1);
	printf ("ft_strcat = %s\n",point2);
	return (0);
}
