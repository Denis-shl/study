/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:31:25 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/22 17:49:10 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				index;
	char			a;

	index = 0;
	a = c;
	while (index != n)
	{
		if (s[index] == a)
			return (s[index]);
		index++;
	}
	return (NULL);
}
