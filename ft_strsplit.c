#include <stdio.h>
#include <stdlib.h>

static unsigned int	ft_size_word(char const *s, char c)
{	
	unsigned int i;
	unsigned int word;

	i = 0;
	word = 0;
	while (*(s + i))
	{
		if(*(s + i ) == c && *(s + i + 1) != c && *(s + i + 1) != '\0')
			word++;
		i++;
	}
	return (word);

}

static char **ft_size_symbol(char **str, char const *s, char c)
{
	unsigned int i;
	unsigned int y;
	unsigned int symbol;
	
	i = 0;
	y = 0;
 	symbol = 0;
	while (*(s + i) != '\0')
	{
			while (*(s + i) != c)
			{
				i++;
				symbol++;
				if (*(s + i) == '\0')
					break ;
			}
			if(symbol != 0)
			{
				if(!(str[y] = (char*)malloc(sizeof(char) * symbol + 1)))
return (0);
y++;
}
			printf("symbol = %d\n",symbol);
		
	symbol = 0;
	i++;
	}

	return(str);
}

static char **ft_algor (char ** str, char const *s, char c)
{
	unsigned int i;
	unsigned int j;
	unsigned int y;

	i = 0;
	y = 0;
	j = 0;
	while(*(s + i))
	{
		while (*(s + i) != c)
		{
			str[y][j] = *(s + i);
			j++;
			i++;
			if (*(s + i) == '\0')
				break ;
		}
		if (j != 0)
		{
			str[y][j] = '\0';
			y++;
		}
		j = 0;
		i++;
		printf("y = %d, i = %d \n",y,i);
	}
	return (str);
}
			
		
char	**ft_strsplit(char const *s, char c)
{
	char **str;
	unsigned int size;
	
	size = 0;
	str = NULL;
	if(!(s))
		return (0);
	size = ft_size_word(s, c);
	if(!(str = (char**)malloc(sizeof(char*) * size)))
		return (0);
	str = ft_size_symbol(str, s, c);
	str = ft_algor(str, s ,c);
	printf("size_word = %d\n",size);
	return (str);
	
}

int main ()
{	
	int i;
	i = 0;	
	char *s = "*Hello**world*denis*shl";
	char **point;
	point = ft_strsplit(s, '*');
	while (i != 4)
	{
		printf("str = %s\n",point[i]);
		i++;
	}


	return(0);
}
