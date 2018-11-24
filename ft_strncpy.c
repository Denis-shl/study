/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:25:23 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/24 17:59:13 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int			index;

	index = 0;
	while (index != len || dst[index])
	{
		if (src[index] == '\0')
			while (index != len)
			{
				dst[index] = '\0';
				index++;
			}
		dst[index] = src[index];
		index++;
	}
	return (dst);
}
