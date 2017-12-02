/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:41:51 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 02:20:51 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			counter;
	unsigned char	*ptr;

	ptr = (unsigned char*)b;
	counter = 0;
	while (counter < len)
	{
		ptr[counter] = c;
		counter++;
	}
	return (b);
}
