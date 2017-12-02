/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uniq_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 09:13:11 by adaly             #+#    #+#             */
/*   Updated: 2017/07/19 05:49:46 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_copy_uniq_strs(char **dst, char **src, uintmax_t size)
{
	uintmax_t	counter;
	uintmax_t	countertwo;

	counter = 0;
	countertwo = 0;
	if (dst && src && size)
	{
		while (counter < size)
		{
			if ((ft_strequ_multi(src[counter], dst, counter) == -1))
			{
				dst[countertwo] = ft_strdup(src[counter]);
				++countertwo;
			}
			++counter;
		}
	}
}

char	**ft_uniq_strs(char **set, uintmax_t size)
{
	uintmax_t	counter;
	char		**tempset;

	tempset = NULL;
	counter = 0;
	if (set)
	{
		if (!size)
			size = ft_arraysize((void**)set);
		tempset = (char**)ft_memalloc(sizeof(char*) * (size + 1));
		if (tempset)
			ft_copy_uniq_strs(tempset, set, size);
	}
	return (tempset);
}
