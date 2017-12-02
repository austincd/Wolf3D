/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 04:32:43 by adaly             #+#    #+#             */
/*   Updated: 2017/06/05 19:38:49 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_three(unsigned int c)
{
	unsigned long	full_char;
	unsigned char	*ptr;

	ptr = (unsigned char*)&(full_char);
	ptr[0] = 0360 | (c >> 18);
	ptr[1] = 0200 | ((c >> 12) & 077);
	ptr[2] = 0200 | ((c >> 6) & 077);
	ptr[3] = 0200 | (c & 077);
	return (full_char);
}

static unsigned long	ft_two(unsigned int c)
{
	unsigned long	full_char;
	unsigned char	*ptr;

	ptr = (unsigned char*)&(full_char);
	ptr[0] = 0340 + ((c >> 12));
	ptr[1] = 0200 | ((c >> 6) & 077);
	ptr[2] = 0200 | (c & 077);
	ptr[3] = 0;
	return (full_char);
}

static unsigned long	ft_one(unsigned int c)
{
	unsigned long	full_char;
	unsigned char	*ptr;

	ptr = (unsigned char*)&(full_char);
	ptr[0] = 0300 | (c >> 6);
	ptr[1] = 0200 | (c & 077);
	ptr[2] = 0;
	ptr[3] = 0;
	return (full_char);
}

unsigned long			ft_char_expand(unsigned long c)
{
	int				full_char;
	int				index;

	index = 1;
	full_char = c;
	if (index)
	{
		if (c >= 65536 && c <= 524287)
			full_char = ft_three(c);
		if (c >= 2048 && c <= 65535)
			full_char = ft_two(c);
		if (c >= 128 && c <= 2047)
			full_char = ft_one(c);
	}
	return (full_char);
}
