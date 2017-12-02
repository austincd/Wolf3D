/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 18:59:58 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 00:53:11 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *append_point;

	append_point = s1 + ft_strlen(s1);
	if (n > (size_t)ft_strlen((char*)s2))
		n = (size_t)ft_strlen((char*)s2);
	if (n > 0)
		ft_strncpy(append_point, s2, n);
	append_point[n] = '\0';
	return (s1);
}
