/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 22:13:47 by adaly             #+#    #+#             */
/*   Updated: 2017/05/18 15:29:13 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_next_square(long long number)
{
	long long test;

	test = 0;
	while (test * test != number)
	{
		++test;
		if (test > (number / 2))
			++number;
	}
	return (number);
}
