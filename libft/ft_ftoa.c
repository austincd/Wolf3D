/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:47:08 by adaly             #+#    #+#             */
/*   Updated: 2017/06/05 19:52:01 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ftoa_helper(long double *num, char **str, long double *power)
{
	int	sign;
	int	counter;

	sign = 0;
	counter = 0;
	if (*num < 0)
	{
		sign = -1;
		*num *= -1;
	}
	while (*num / *power >= 10)
	{
		*power = ft_power(counter, 10);
		++counter;
	}
	*str = ft_strnew(counter + 9);
	if (sign == -1)
		ft_charcat(*str, '-');
	return (counter);
}

char			*ft_ftoa(long double num)
{
	char		*str;
	int			counter;
	long double	power;
	char		*digits;

	digits = ft_strdup("01234567890");
	power = 1;
	str = NULL;
	counter = ft_ftoa_helper(&num, &str, &power);
	while (num >= 0.000000000000000001 || counter > -7)
	{
		if (counter == -6)
			ft_charcat(str, digits[(long long)((num / power) + .5)]);
		else
			ft_charcat(str, digits[(long long)((num / power) + .1)]);
		num = ft_floatmod(num, power);
		if (counter == 0)
			ft_charcat(str, '.');
		power = ft_power(--counter, 10);
	}
	return (str);
}
