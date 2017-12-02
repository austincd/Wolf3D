/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:14:44 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 02:04:57 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrchr(const void *s, int c, size_t n)
{
	size_t			counter;
	void			*found_location;
	unsigned char	*search_area;

	search_area = (unsigned char*)s;
	counter = 0;
	found_location = NULL;
	while (counter < n)
	{
		if (search_area[counter] == c)
			found_location = &(search_area[counter]);
		counter++;
	}
	return (found_location);
}
