/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 01:02:16 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 02:05:36 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*start;
	int		which;

	which = (size_t)ft_strlen((char*)little);
	start = (char*)big;
	if (little[0] == '\0')
		return ((char*)big);
	while (*start != '\0')
	{
		if (ft_strchr(start, little[0]))
		{
			start = ft_strchr(start, little[0]);
			if (ft_strncmp(start, little, which) == 0)
				return (start);
			else if (*start != '\0')
				start += 1;
		}
		else
			return (NULL);
	}
	return (NULL);
}
