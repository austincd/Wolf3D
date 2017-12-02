/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:49:06 by adaly             #+#    #+#             */
/*   Updated: 2017/06/06 20:42:32 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width(t_pfconv *current)
{
	long long	length;

	length = 0;
	if (current)
	{
		if (current->width > 0)
		{
			if (ft_lowercase(current->type) == 'c')
				length = current->width - 1;
			else
				length = current->width - (ft_strlen(current->string));
			if (length > 0)
			{
				current->widthstr = ft_strnew(length);
				ft_memset(current->widthstr, ' ', length);
			}
		}
	}
}
