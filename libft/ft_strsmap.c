/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:40:39 by adaly             #+#    #+#             */
/*   Updated: 2017/09/15 16:43:57 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**takes a null-terminated array of strings and a pointer to a function. The
**function is called on each element of the array, and the return value of each
**call is put in a new array to be returned once all elements of the input have
**been processed
*/

#include "libft.h"

char	**ft_strsmap(char **input, char *(*f)(char *str))
{
	char		**new;

	new = NULL;
	if (input && f)
	{
		new = (char**)ft_arraydup((void**)input);
		if (new)
			new = ft_strsmapin(new, f);
	}
	return (new);
}

char	**ft_strsmapin(char **input, char *(*f)(char *ptr))
{
	uintmax_t	size;
	uintmax_t	counter;

	counter = 0;
	size = 0;
	if (input && f)
	{
		size = ft_arraysize((void**)input);
		while (counter < size)
		{
			input[counter] = f(input[counter]);
			++counter;
		}
	}
	return (input);
}
