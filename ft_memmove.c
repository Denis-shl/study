/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:50:50 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/22 17:30:45 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int index;
	char *str;

	index = 0;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	while (index != len)
	{
		str[index] = src[index];
		index++;
	}
	str[index] = '\0';
	index = 0; 
	while (str)
	{
		dst[index] = srt[index];
		index++;
	}
	return (dst);
}
