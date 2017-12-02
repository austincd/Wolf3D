/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 11:27:52 by adaly             #+#    #+#             */
/*   Updated: 2017/08/15 11:32:16 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	ft_factorial(uintmax_t num)
{
	uintmax_t	total;
	uintmax_t	counter;

	total = 0;
	counter = 1;
	if (num > 1)
	{
		total = 1;
		while (counter <= num)
		{
			total *= counter;
			++counter;
		}
	}
	return (total);
}
