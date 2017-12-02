/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 08:56:00 by adaly             #+#    #+#             */
/*   Updated: 2017/09/15 16:53:21 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Takes in a null-terminated array of pointers, duplicates that array, and
**returns the duplicate.
*/

void	**ft_arraydup(void **input)
{
	void		**output;
	uintmax_t	size;
	uintmax_t	counter;

	size = 0;
	counter = 0;
	output = NULL;
	if (input)
	{
		size = ft_arraysize(input);
		if (size)
		{
			output = (void**)ft_memalloc(sizeof(void*) * (size + 1));
			if (output)
			{
				while (*input)
				{
					output[counter] = *input;
					++input;
					++counter;
				}
			}
		}
	}
	return (output);
}
