/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:14:44 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 02:07:27 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			counter;
	void			*found_location;
	unsigned char	*search_area;

	counter = 0;
	search_area = (unsigned char*)s;
	found_location = NULL;
	while (counter < n && found_location == NULL)
	{
		if (search_area[counter] == (unsigned char)c)
			found_location = &(search_area[counter]);
		counter++;
	}
	return (found_location);
}
