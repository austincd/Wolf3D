/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delimcountto.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:18:12 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 06:04:17 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isdelim(char c, char delim)
{
	if (c == delim)
		return (1);
	return (0);
}

char		*ft_delimcountto(char *str, unsigned char c, int index)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = str;
	while (*ptr != '\0' && count < index)
	{
		while (*ptr != '\0' && count < index && ft_isdelim(*ptr, c) == 1)
			ptr++;
		if (*ptr != '\0')
			count++;
		while (*ptr != '\0' && count < index && ft_isdelim(*ptr, c) == 0)
			ptr++;
	}
	return (ptr);
}
