/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_how_many_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 19:31:37 by adaly             #+#    #+#             */
/*   Updated: 2017/05/18 15:25:03 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_how_many_char(char *str, char c)
{
	long long counter;

	counter = 0;
	if (str)
	{
		while (*str)
		{
			if (*str == c)
				++counter;
			++str;
		}
	}
	return (counter);
}
