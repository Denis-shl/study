/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:25:17 by oargrave          #+#    #+#             */
/*   Updated: 2019/02/13 23:21:45 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *str, size_t prev, size_t size)
{
	void			*new;

	if (!str)
		return (NULL);
	if (!(new = ft_memalloc(size)))
	{
		free(str);
		return (NULL);
	}
	ft_memcpy(new, str, prev);
	free(new);
	return (new);
}
