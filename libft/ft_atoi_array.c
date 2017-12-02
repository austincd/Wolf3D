/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 05:15:21 by adaly             #+#    #+#             */
/*   Updated: 2017/09/15 17:25:12 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_atoi_array(char *s)
{
	int *ret;
	int i;

	ret = (int *)ft_memalloc((ft_numcount(s) * sizeof(int)) + 1);
	i = 0;
	while (*s)
	{
		if (*s == '-' || ft_isdigit(*s))
			ret[++i] = ft_atoi(s);
		s = ((ft_strclen(s, ' ')) ? s + ft_strclen(s, ' ') : s + 1);
	}
	ret[0] = i;
	return (ret);
}
