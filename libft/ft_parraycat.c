/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parraycat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 10:37:36 by adaly             #+#    #+#             */
/*   Updated: 2017/08/15 10:40:36 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_parraycat(void **array, void *ptr)
{
	uintmax_t	counter;

	counter = 0;
	if (array && ptr)
	{
		while (array[counter])
			++counter;
		if (!array[counter])
			array[counter] = ptr;
	}
}
