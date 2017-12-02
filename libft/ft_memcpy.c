/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:59:34 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 02:03:12 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t			counter;
	unsigned char	*source;

	source = (unsigned char*)src;
	counter = 0;
	while (counter < n)
	{
		ft_memset(dst + counter, source[counter], 1);
		counter++;
	}
	return (dst);
}
