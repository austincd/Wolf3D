/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:18:03 by adaly             #+#    #+#             */
/*   Updated: 2017/01/19 07:58:32 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int length;

	length = 0;
	if (src && dst)
	{
		length = ft_strlen((char*)src);
		if (size > (size_t)length + 1)
			size = length + 1;
		if (dst && src)
		{
			if (size > 0)
			{
				ft_strncpy(dst, src, (size - 1));
				dst[(size - 1)] = '\0';
			}
			else
				dst[size] = '\0';
		}
	}
	return (length);
}
