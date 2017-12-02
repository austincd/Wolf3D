/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:05:52 by adaly             #+#    #+#             */
/*   Updated: 2017/02/06 13:38:18 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		length;

	length = 0;
	joined = NULL;
	if (s1 && s2)
	{
		length = ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1;
		joined = (char*)malloc(length);
		if (joined)
		{
			ft_strcpy(joined, (char*)s1);
			ft_strcat(joined, (char*)s2);
		}
	}
	return (joined);
}
