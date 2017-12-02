/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delimcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:18:12 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 06:08:59 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isdelim(char c, char delim)
{
	if (c == delim)
		return (1);
	return (0);
}

int				ft_delimcount(char *str, unsigned char c)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = str;
	if (ptr)
	{
		while (*ptr != '\0')
		{
			while (*ptr != '\0' && ft_isdelim(*ptr, (char)c) == 1)
				ptr++;
			if (*ptr != '\0')
				count++;
			while (*ptr != '\0' && ft_isdelim(*ptr, (char)c) == 0)
				ptr++;
		}
	}
	return (count);
}
