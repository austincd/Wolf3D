/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraytrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 08:51:15 by adaly             #+#    #+#             */
/*   Updated: 2017/09/15 16:53:02 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Takes in a null-terminated array of pointers and replaces it with a duplicate
**before freeing the original. This is done to free memory that was initially
**allocated to the original that was unused.
*/

void		ft_arraytrim(void ***array)
{
	void	**duplicate;

	duplicate = NULL;
	duplicate = ft_arraydup(*array);
	if (duplicate)
	{
		free(*array);
		*array = duplicate;
	}
}
