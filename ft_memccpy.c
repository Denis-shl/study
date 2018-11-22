/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:38:58 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/22 15:55:47 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int index;
	int flag;
	char a;

	index = 0; 
	a = c;
	flag = 0;
	while (index != n)
	{
		if (src[index] == a)
			flag = 1;
		dst[index] = src[index];
		index++;
	}
	if (flag == 0)
		return (NULL);
	return (dst);
}
