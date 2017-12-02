/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:09:32 by adaly             #+#    #+#             */
/*   Updated: 2017/06/05 19:31:24 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_power(long long power, long long base)
{
	int			sign;
	long long	counter;
	long double	ret;

	ret = 1;
	counter = 0;
	sign = 0;
	if (!power)
		return (1);
	if (power < 0)
	{
		sign = -1;
		power *= -1;
	}
	while (counter < power)
	{
		ret *= base;
		++counter;
	}
	if (sign == -1)
		ret = 1 / ret;
	return (ret);
}
