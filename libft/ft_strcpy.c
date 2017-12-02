/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 22:23:12 by adaly             #+#    #+#             */
/*   Updated: 2017/06/10 19:30:46 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, char *src)
{
	int str_place;

	str_place = 0;
	while (src[str_place] != '\0')
	{
		dst[str_place] = src[str_place];
		str_place++;
	}
	dst[str_place] = '\0';
	return (dst);
}

wchar_t	*ft_wstrcpy(wchar_t *dst, wchar_t *src)
{
	uintmax_t str_place;

	str_place = 0;
	while (src[str_place] != '\0')
	{
		dst[str_place] = src[str_place];
		str_place++;
	}
	dst[str_place] = '\0';
	return (dst);
}
