/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floatmod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:14:27 by adaly             #+#    #+#             */
/*   Updated: 2017/06/05 19:14:29 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double		ft_floatmod(long double alpha, long double beta)
{
	long double		temp;
	long long		counter;

	temp = 0;
	counter = 0;
	while (alpha - temp >= 0)
	{
		temp = beta * counter;
		++counter;
	}
	if (alpha - temp < 0)
		temp = beta * (counter - 2);
	return (alpha - temp);
}
