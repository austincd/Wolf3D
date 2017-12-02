/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:59:34 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 02:08:15 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			counter;
	unsigned char	*dest;
	unsigned char	*surc;
	void			*return_ptr;

	dest = (unsigned char*)dst;
	surc = (unsigned char*)src;
	counter = 0;
	return_ptr = NULL;
	while (counter < n)
	{
		dest[counter] = surc[counter];
		if (dest[counter] == (unsigned char)c)
			return (dst + counter + 1);
		counter++;
	}
	return (return_ptr);
}
