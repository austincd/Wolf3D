/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basefloat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 15:18:23 by adaly             #+#    #+#             */
/*   Updated: 2017/06/04 15:19:30 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_basefloat_helper(long double num, int *nums, \
long double power, char *digits)
{
	char	*str;

	str = ft_strnew(nums[1] + 9);
	if (nums[0] == -1)
		ft_charcat(str, '-');
	while (num >= 0.000000000000000001)
	{
		ft_charcat(str, digits[(long long)((num / power))]);
		num = ft_floatmod(num, power);
		if (power == 1 && num >= 0.000000000000000001)
			ft_charcat(str, '.');
		power = ft_power(--nums[1], nums[2]);
	}
	return (str);
}

char			*ft_basefloat(long double num, int base)
{
	long double	power;
	char		*digits;
	char		*str;
	int			nums[3];

	digits = ft_strdup("0123456789ABCDEF");
	power = 1;
	nums[1] = 0;
	nums[0] = 0;
	if (num < 0)
	{
		nums[0] = -1;
		num *= -1;
	}
	while (num / power >= base)
	{
		power = ft_power(nums[1], base);
		++nums[1];
	}
	nums[2] = base;
	str = ft_basefloat_helper(num, nums, power, digits);
	return (str);
}
