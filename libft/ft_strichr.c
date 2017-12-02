/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:48:41 by adaly             #+#    #+#             */
/*   Updated: 2017/06/02 17:03:21 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strichr(const char *s, int c)
{
	char	*big;
	char	*little;
	int		index;

	index = 0;
	big = ft_strchr(s, ft_toupper(c));
	little = ft_strchr(s, ft_tolower(c));
	index = big - s;
	if ((little - s) < index)
		index = little - s;
	return ((char*)s + index);
}
