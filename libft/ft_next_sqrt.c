/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_sqrt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 22:13:47 by adaly             #+#    #+#             */
/*   Updated: 2017/05/18 14:59:05 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_next_sqrt(long long number)
{
	long long test;

	if (number <= 1)
		return (1);
	test = 0;
	while (test * test != number)
	{
		++test;
		if (test > number)
		{
			++number;
			test = 0;
		}
	}
	return (test);
}
