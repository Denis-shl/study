/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:54:17 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/24 17:54:53 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	int			index;

	index = 0;
	while (src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	return (dst);
}
