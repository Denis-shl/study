/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:42:42 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/02 16:27:45 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int		ft_abs(int num)
{
	if (num == -2147483648)
		return (-1);
	else if (num < 0)
		return (-num);
	else
		return (num);
}
