/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combine_arrays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 17:41:33 by adaly             #+#    #+#             */
/*   Updated: 2017/09/15 16:57:10 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**combines any number of null terminated pointer arrays into a single array
*/

#include "libft.h"

static uintmax_t	ft_combine_arrays_total(void ***arrays, \
uintmax_t *num_arrays)
{
	uintmax_t	total_elements;

	total_elements = 0;
	*num_arrays = 0;
	if (arrays)
	{
		while (arrays[*num_arrays])
		{
			total_elements += ft_arraysize(arrays[*num_arrays]);
			++(*num_arrays);
		}
	}
	return (total_elements);
}

static uintmax_t	ft_arraycpy(void **dst, void **src)
{
	uintmax_t	counter;

	counter = 0;
	if (dst && src)
	{
		while (src[counter])
		{
			dst[counter] = src[counter];
			++counter;
		}
	}
	return (counter);
}

void				**ft_combine_arrays(void ***arrays)
{
	uintmax_t	num_arrays;
	uintmax_t	total_elements;
	uintmax_t	copied;
	uintmax_t	counter;
	void		**new;

	copied = 0;
	counter = 0;
	total_elements = ft_combine_arrays_total(arrays, &num_arrays);
	new = (void**)ft_memalloc(sizeof(void*) * (total_elements + 1));
	if (new)
	{
		while (counter < num_arrays)
		{
			copied += ft_arraycpy(new + copied, arrays[counter]);
			++counter;
		}
	}
	return (new);
}
