/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 22:23:12 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 02:04:07 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t str_place;

	str_place = 0;
	while (str_place < len && src[str_place] != '\0')
	{
		dst[str_place] = src[str_place];
		str_place++;
	}
	if (str_place < len)
	{
		while (str_place < len)
		{
			dst[str_place] = '\0';
			str_place++;
		}
	}
	return (dst);
}
