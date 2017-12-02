/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replacechar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 09:47:35 by adaly             #+#    #+#             */
/*   Updated: 2017/09/15 16:58:59 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Finds all occurances of a particular byte value in a region of memory
**and replaces them with another byte value. returns the number of occurances
**that were replaced.
*/

uintmax_t		ft_replacebyte(void *mem, uintmax_t size, \
unsigned char alpha, unsigned char beta)
{
	unsigned char		*found;
	uintmax_t			counter;

	counter = 0;
	found = NULL;
	if (mem && size)
	{
		while ((found = ft_memchr(mem, alpha, size)))
		{
			*found = beta;
			++counter;
		}
	}
	return (counter);
}

uintmax_t		ft_replacechar(char *str, unsigned char alpha, \
unsigned char beta)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)str;
	return (ft_replacebyte((void*)ptr, ft_strlen(str), alpha, beta));
}
