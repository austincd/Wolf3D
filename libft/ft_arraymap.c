/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraymap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:45:36 by adaly             #+#    #+#             */
/*   Updated: 2017/09/15 16:52:42 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**takes a null-terminated array of pointers and a pointer to a function. The
**function is called on each element of the array, and the return value of each
**call is put in a new array to be returned once all elements of the input have
**been processed
*/

#include "libft.h"

void	**ft_arraymap(void **input, void *(*f)(void *ptr))
{
	void		**new;

	new = NULL;
	if (input && f)
	{
		new = ft_arraydup(input);
		if (new)
			new = ft_arraymapin(new, f);
	}
	return (new);
}

void	**ft_arraymapin(void **input, void *(*f)(void *ptr))
{
	uintmax_t	size;
	uintmax_t	counter;

	counter = 0;
	size = 0;
	if (input && f)
	{
		size = ft_arraysize(input);
		while (counter < size)
		{
			input[counter] = f(input[counter]);
			++counter;
		}
	}
	return (input);
}
