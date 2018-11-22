/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:50:10 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/22 17:56:04 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int			index;

	index = 0;
	while (index != n && s1[index] == s2[index])
	{
		index++;
	}
	return (s1[index] - s2[index]);
}
