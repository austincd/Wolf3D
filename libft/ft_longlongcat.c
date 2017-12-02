/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlongcat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:42:27 by adaly             #+#    #+#             */
/*   Updated: 2017/02/06 12:49:14 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	*ft_longlongcat(long long *array, long long val)
{
	long long index;

	index = 0;
	if (array)
	{
		while (array[index])
			++index;
		array[index] = val;
		return (array + index);
	}
	return (NULL);
}
