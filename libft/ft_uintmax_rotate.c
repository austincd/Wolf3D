/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmax_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 09:37:36 by adaly             #+#    #+#             */
/*   Updated: 2017/09/15 16:44:23 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_uintmax_rot_internal(uintmax_t *array, uintmax_t size)
{
	uintmax_t	temp;
	uintmax_t	counter;

	counter = 0;
	temp = 0;
	if (array)
	{
		temp = array[0];
		while (counter < (size - 1))
		{
			array[counter] = array[counter + 1];
			++counter;
		}
		array[counter] = temp;
	}
}

static void		ft_uintmax_revrot_internal(uintmax_t *array, uintmax_t size)
{
	uintmax_t	temp;
	uintmax_t	counter;

	counter = 1;
	temp = 0;
	if (array)
	{
		temp = array[size - 1];
		while (counter < size)
		{
			array[counter] = array[counter - 1];
			++counter;
		}
		array[0] = temp;
	}
}

void			ft_uintmax_rotate(uintmax_t *array, uintmax_t size, \
uintmax_t num_rots)
{
	uintmax_t	counter;

	counter = 0;
	while (counter < num_rots)
	{
		ft_uintmax_rot_internal(array, size);
		++counter;
	}
}

void			ft_uintmax_revrotate(uintmax_t *array, uintmax_t size, \
uintmax_t num_rots)
{
	uintmax_t	counter;

	counter = 0;
	while (counter < num_rots)
	{
		ft_uintmax_revrot_internal(array, size);
		++counter;
	}
}
