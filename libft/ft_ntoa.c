/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 00:34:54 by adaly             #+#    #+#             */
/*   Updated: 2017/06/08 00:35:22 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen_base(uintmax_t num, unsigned int base)
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

static void	ft_itoa_internal(char *str, uintmax_t num, unsigned int base)
{
	char	digits[17];

	ft_strlcpy(digits, "0123456789ABCDEF", 17);
	if (str)
	{
		if (num < base)
			ft_charcat(str, digits[num]);
		else if (num >= base)
		{
			ft_itoa_internal(str, num / base, base);
			ft_itoa_internal(str, num % base, base);
		}
	}
}

static char	*ft_fuck_printf(void)
{
	return (ft_strdup("-9223372036854775808"));
}

char		*ft_ntoa(uintmax_t val, unsigned int base, short sign)
{
	int			length;
	char		*new;

	new = NULL;
	if (val == 9223372036854775808ull && sign)
		return (ft_fuck_printf());
	if (base >= 2 && base <= 16)
	{
		if (sign == -1)
		{
			if (base == 10)
			{
				length = ft_numlen_base(val, base) + 1;
				new = ft_strnew(length);
				ft_charcat(new, '-');
			}
		}
		length = ft_numlen_base(val, base);
		if (!new)
			new = ft_strnew(length);
		ft_itoa_internal(new, val, base);
	}
	return (new);
}
