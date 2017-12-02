/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 14:12:03 by adaly             #+#    #+#             */
/*   Updated: 2017/09/15 17:30:05 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**return the number of times a character c is found in string str
*/

uintmax_t	ft_charcount(char *str, char c)
{
	uintmax_t	occurances;
	uintmax_t	counter;

	occurances = 0;
	counter = 0;
	if (str)
	{
		while (str[counter])
		{
			if (str[counter] == c)
				++occurances;
			++counter;
		}
	}
	return (occurances);
}

int			ft_numcount(const char *s)
{
	int count;
	int i;

	count = 0;
	i = -1;
	while (s[++i])
		if (ft_isdigit(s[i]) && !ft_isdigit(s[i + 1]))
			count++;
	return (count);
}
