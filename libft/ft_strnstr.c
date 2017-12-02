/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 01:02:16 by adaly             #+#    #+#             */
/*   Updated: 2017/01/21 02:15:03 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*dupe;
	char	*found;
	char	*in_big;
	size_t	loc;

	dupe = (char*)malloc(len + 1);
	ft_strncpy(dupe, big, len);
	dupe[len] = '\0';
	in_big = NULL;
	if (ft_strstr(dupe, little))
	{
		found = ft_strstr(dupe, little);
		loc = (found - dupe);
		in_big = ((char*)big + loc);
	}
	free((char*)dupe);
	return (in_big);
}
