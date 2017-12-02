/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 00:19:08 by adaly             #+#    #+#             */
/*   Updated: 2017/06/08 00:35:34 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(intmax_t num, int base)
{
	int			sign;
	uintmax_t	unum;
	char		*str;

	sign = 1;
	if (num < 0)
	{
		unum = num * -1;
		sign = -1;
	}
	else
	{
		unum = num;
	}
	str = ft_ntoa(unum, base, sign);
	return (str);
}
