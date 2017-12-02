/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:08:48 by adaly             #+#    #+#             */
/*   Updated: 2017/06/05 19:09:17 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen_base(unsigned long long num, unsigned int base)
{
	int counter;

	counter = 0;
	if (!num)
		return (1);
	while (num)
	{
		num /= base;
		++counter;
	}
	return (counter);
}

static void	ft_utoa_internal(char *str, \
unsigned long long num, unsigned int base)
{
	char	digits[17];

	ft_strlcpy(digits, "0123456789ABCDEF", 17);
	if (str)
	{
		if (num < base)
			ft_charcat(str, digits[num]);
		else if (num >= base)
		{
			ft_utoa_internal(str, num / base, base);
			ft_utoa_internal(str, num % base, base);
		}
	}
}

char		*ft_utoa_base(unsigned long long val, unsigned int base)
{
	int			length;
	char		*new;

	new = NULL;
	if (base >= 2 && base <= 16)
	{
		length = ft_numlen_base(val, base);
		if (!new)
			new = ft_strnew(length);
		ft_utoa_internal(new, val, base);
	}
	return (new);
}
