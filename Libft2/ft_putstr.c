
void	ft_putstr(char const *s)
{
	int	index;
	char	*point;

	point = (char *) s;
	index = 0;
	while(point[index] != '\0')
	{
		ft_putchar(point[index]);
		index++;
	}
}
	
