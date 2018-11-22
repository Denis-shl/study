/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:56:27 by oargrave          #+#    #+#             */
/*   Updated: 2018/11/22 17:58:20 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	strlen(const char *s)
{
	size_t index;

	index = 0;
	while (s[index] != '\0')
	{
		index++;
	}
	return (index);
}
