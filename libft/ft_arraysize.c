/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraysize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 09:17:43 by adaly             #+#    #+#             */
/*   Updated: 2017/09/15 16:46:37 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**finds the size of a null terminated array of pointers
*/

#include "libft.h"

uintmax_t	ft_arraysize(void **array)
{
	uintmax_t	ret;

	ret = 0;
	if (array)
	{
		while (array[ret])
			++ret;
	}
	return (ret);
}
