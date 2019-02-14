/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:50:27 by oargrave          #+#    #+#             */
/*   Updated: 2018/12/21 20:45:56 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*point;

	if (!(point = (t_list*)malloc(sizeof(*point))))
		return (NULL);
	if (!content)
	{
		point->content = NULL;
		point->content_size = 0;
	}
	else
	{
		if (!(point->content = malloc(content_size)))
		{
			free(point);
			return (NULL);
		}
		ft_memcpy(point->content, content, content_size);
		point->content_size = content_size;
	}
	point->next = NULL;
	return (point);
}
