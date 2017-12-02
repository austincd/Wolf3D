/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 08:23:32 by adaly             #+#    #+#             */
/*   Updated: 2017/09/15 17:00:50 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Takes in a null-terminated array of strings and two functions as parameters.
**Each string in the array is piped into the first function, and the return
**value of the first function is checked by the second function. if the second
**function returns true, a copy of the string is added to a new array. if not,
**the str is passed over. After all the strings have been processed, the new
**array is returned.
*/

char		**ft_check_strs(char **input_strs, \
void *(*alpha)(char *str), int *(*beta)(void *ret_val))
{
	char		**output_strs;
	uintmax_t	counter;

	counter = 0;
	output_strs = NULL;
	if (input_strs && alpha && beta)
	{
		output_strs = (char**)ft_memalloc(sizeof(char*) * \
						(ft_arraysize((void**)input_strs) + 1));
		if (output_strs)
		{
			while (*input_strs)
			{
				if (beta(alpha(*input_strs)))
				{
					output_strs[counter] = ft_strdup(*input_strs);
					++counter;
				}
				++input_strs;
			}
		}
	}
	ft_arraytrim((void***)&output_strs);
	return (output_strs);
}
