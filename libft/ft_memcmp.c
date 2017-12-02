/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 20:43:43 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 06:01:15 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_unsn_charcmp(unsigned char alpha, unsigned char beta)
{
	return (alpha - beta);
}

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			counter;
	int				return_value;
	unsigned char	*s1_char;
	unsigned char	*s2_char;

	counter = 0;
	return_value = 0;
	s1_char = (unsigned char*)s1;
	s2_char = (unsigned char*)s2;
	while (counter < n && return_value == 0)
	{
		return_value = ft_unsn_charcmp(s1_char[counter], s2_char[counter]);
		counter++;
	}
	return (return_value);
}
