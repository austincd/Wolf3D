/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:10:25 by adaly             #+#    #+#             */
/*   Updated: 2017/01/19 04:36:21 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *dest;

	dest = NULL;
	if (s)
	{
		dest = (char*)ft_memalloc(len + 1);
		if (dest)
			ft_strncpy(dest, &(s[start]), len);
	}
	return (dest);
}
