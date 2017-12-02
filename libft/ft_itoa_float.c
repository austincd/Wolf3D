/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 05:09:48 by adaly             #+#    #+#             */
/*   Updated: 2017/06/08 00:28:27 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_float(long double num, int base)
{
	long long	integer;
	long long	decimal;
	long double	temp;
	char		*new;

	integer = num / 1;
	temp = num - integer;
	decimal = 0;
	while (decimal < 9)
	{
		temp *= 10;
		++decimal;
	}
	decimal = (long long)temp;
	new = ft_strjoin(ft_itoa_base(integer, base), ".");
	ft_restrcat(&new, ft_itoa_base(decimal, base));
	temp -= decimal;
	temp *= 100000;
	decimal = (long long)temp;
	ft_restrcat(&new, ft_itoa_base(decimal, base));
	return (new);
}
